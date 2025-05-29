%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

typedef struct Node {
    char *type;
    char *value;
    struct Node **children;
    int child_count;
} Node;

Node *create_node(char *type, char *value);
void print_ast(Node *node, int depth);
%}

%union {
    char *id;
    int num;
    char *str;
    struct Node *node;
}

%token <id> IDENTIFIER
%token <str> STRING
%token <num> NUMBER

%token START END DEFINE STRUCTURE INHERIT BRANCH PROOF TRUTH TEXTURE ROUTE CHANNEL LINKER MODIFIER REPEAT UNTIL ECHO AWAIT EMIT WITHIN BEGIN HALT

%token ARROW COLON RANGE PLUS MINUS MUL DIV ASSIGN LPAREN RPAREN LBRACE RBRACE COMMA

%type <node> program statement define_block echo_stmt expr

%%

program:
    START statement_list END    { print_ast($2, 0); }
    ;

statement_list:
    statement                  { $$ = $1; }
    | statement_list statement
    ;

statement:
    define_block               { $$ = $1; }
    | echo_stmt                { $$ = $1; }
    ;

define_block:
    DEFINE IDENTIFIER ARROW IDENTIFIER COLON statement_list END {
        $$ = create_node("Define", $2);
    }
    ;

echo_stmt:
    ECHO STRING                {
        $$ = create_node("Echo", $2);
    }
    ;

expr:
    STRING                     { $$ = create_node("String", $1); }
    | NUMBER                   { $$ = create_node("Number", NULL); }
    | IDENTIFIER               { $$ = create_node("Identifier", $1); }
    ;

%%

Node *create_node(char *type, char *value) {
    Node *node = malloc(sizeof(Node));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void print_ast(Node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("[%s] %s\n", node->type, node->value ? node->value : "");
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}