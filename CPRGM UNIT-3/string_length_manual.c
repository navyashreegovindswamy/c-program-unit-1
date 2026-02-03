#include <stdio.h>
#include <stdlib.h>

// Find length of string without using strlen
int string_length(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) input = argv[1];
    else {
        static char buf[1024];
        printf("Enter a string: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[string_length(buf)] = '\0'; // remove newline
        // Find length before newline
        int i = 0;
        while (buf[i] != '\0' && buf[i] != '\n' && buf[i] != '\r') i++;
        buf[i] = '\0';
        input = buf;
    }

    int len = string_length(input);
    printf("String: \"%s\"\n", input);
    printf("Length: %d\n", len);
    return 0;
}
