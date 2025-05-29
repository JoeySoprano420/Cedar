#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NASM x64 minimal Hello World static assembly output

void generate_nasm_hello() {
    FILE *f = fopen("hello.asm", "w");
    if (!f) {
        perror("Unable to write NASM output");
        return;
    }

    fprintf(f,
        "section .data\n"
        "    hello db 'Hello, from Cedar.', 0xA, 0\n\n"
        "section .text\n"
        "    global _start\n\n"
        "_start:\n"
        "    mov edx, 20         ; message length\n"
        "    mov ecx, hello      ; message to write\n"
        "    mov ebx, 1          ; file descriptor (stdout)\n"
        "    mov eax, 4          ; syscall number (sys_write)\n"
        "    int 0x80            ; call kernel\n\n"
        "    mov eax, 1          ; syscall number (sys_exit)\n"
        "    xor ebx, ebx        ; exit code 0\n"
        "    int 0x80\n"
    );

    fclose(f);
    printf("✅ NASM output generated: hello.asm\n");
}