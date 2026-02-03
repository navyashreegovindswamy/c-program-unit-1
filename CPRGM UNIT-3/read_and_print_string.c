#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char str[1024];

    if (argc > 1) {
        // Use command-line argument
        strcpy(str, argv[1]);
    } else {
        // Read from stdin
        printf("Enter a string: ");
        fflush(stdout);
        if (!fgets(str, sizeof str, stdin)) {
            return 0;
        }
        // Remove trailing newline
        str[strcspn(str, "\r\n")] = '\0';
    }

    printf("Output: %s\n", str);
    return 0;
}
