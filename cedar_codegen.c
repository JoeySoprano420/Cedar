#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cedar_ast.c"

// LLVM-compatible IR emitter (C-style intermediate IR as output)

void emit_ir(Node *node) {
    if (!node) return;

    if (strcmp(node->type, "Echo") == 0) {
        printf("  call void @print_string(i8* getelementptr inbounds ([%lu x i8], [%lu x i8]* @.str, i32 0, i32 0))\n",
               strlen(node->value) + 1, strlen(node->value) + 1);
    }

    for (int i = 0; i < node->child_count; i++) {
        emit_ir(node->children[i]);
    }
}

void emit_preamble(const char *string_literal) {
    printf("@.str = private unnamed_addr constant [%lu x i8] c\"%s\\00\", align 1\n", strlen(string_literal) + 1, string_literal);
    printf("declare void @print_string(i8*)\n\n");
    printf("define i32 @main() {\n");
}

void emit_postamble() {
    printf("  ret i32 0\n");
    printf("}\n");
}