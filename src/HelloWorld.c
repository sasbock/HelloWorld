#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

// Function with buffer overflow vulnerability
void vulnerable_copy(char *input) {
    char buffer[BUFFER_SIZE];
    // Unsafe: no bounds checking
    strcpy(buffer, input);
    printf("Copied input: %s\n", buffer);
}

// Function with format string vulnerability
void vulnerable_printf(char *input) {
    // Unsafe: user input used as format string
    printf(input, "Hello, world!\n");
    printf("\n");
}

// Function demonstrating use-after-free
void use_after_free() {
    char *data = (char *)malloc(32);
    if (!data) return;

    strcpy(data, "Temporary data");
    free(data);

    // Unsafe: using memory after it has been freed
    printf("Use-after-free: %s\n", data);
}

void use_after_free2() {
    char *data = (char *)malloc(32);
    if (!data) return;

    strcpy(data, "Temporary data");
    free(data);

    // Unsafe: using memory after it has been freed
    printf("Use-after-free: %s\n", data);
}

// Function demonstrating integer overflow
void integer_overflow() {
    int a = 2147483647; // INT_MAX
    int b = 10;
    int result = a + b; // Overflow occurs

    printf("Overflow result: %d\n", result);
}

// Function demonstrating command injection risk
void command_injection(char *input) {
    char command[64];

    // Unsafe: user input directly used in system command
    snprintf(command, sizeof(command), "echo %s", input);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    printf("Running vulnerable functions...\n");

    vulnerable_copy(argv[1]);
    vulnerable_printf(argv[1]);
    use_after_free();
    integer_overflow();
    command_injection(argv[1]);

    return 0;
}

