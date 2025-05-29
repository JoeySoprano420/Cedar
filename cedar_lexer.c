%{
#include "cedar_parser.tab.h"
#include <string.h>

void yyerror(const char *s);
%}

%x COMMENT

%%
"start"             { return START; }
"end"               { return END; }
"define"            { return DEFINE; }
"structure"         { return STRUCTURE; }
"inherit"           { return INHERIT; }
"branch"            { return BRANCH; }
"proof"             { return PROOF; }
"truth"             { return TRUTH; }
"texture"           { return TEXTURE; }
"route"             { return ROUTE; }
"channel"           { return CHANNEL; }
"linker"            { return LINKER; }
"modifier"          { return MODIFIER; }
"repeat"            { return REPEAT; }
"until"             { return UNTIL; }
"echo"              { return ECHO; }
"await"             { return AWAIT; }
"emit"              { return EMIT; }
"within"            { return WITHIN; }
"begin"             { return BEGIN; }
"halt"              { return HALT; }

"->"                { return ARROW; }
":"                 { return COLON; }
".."                { return RANGE; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"="                 { return ASSIGN; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
","                 { return COMMA; }

\"([^\\\"]|\\.)*\"  { yylval.str = strdup(yytext); return STRING; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return IDENTIFIER; }

[\t ]+              ;
[\r\n]+             ;
.                   { return *yytext; }
%%

int yywrap(void) {
    return 1;
}