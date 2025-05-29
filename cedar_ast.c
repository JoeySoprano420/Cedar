#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *type;
    char *value;
    struct Node **children;
    int child_count;
} Node;

Node *create_node(char *type, char *value) {
    Node *node = malloc(sizeof(Node));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node *parent, Node *child) {
    if (!parent || !child) return;
    parent->children = realloc(parent->children, sizeof(Node *) * (parent->child_count + 1));
    parent->children[parent->child_count++] = child;
}

void print_ast(Node *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("[%s] %s\n", node->type, node->value ? node->value : "");
    for (int i = 0; i < node->child_count; i++) {
        print_ast(node->children[i], depth + 1);
    }
}