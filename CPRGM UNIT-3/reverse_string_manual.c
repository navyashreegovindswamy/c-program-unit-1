#include <stdio.h>
#include <stdlib.h>

// Find length of string manually
int string_length(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Reverse string manually without using built-in functions
char *reverse_string(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    char *reversed = malloc((size_t)n + 1);
    if (!reversed) return NULL;

    // Copy characters in reverse order
    for (int i = 0; i < n; ++i) {
        reversed[i] = str[n - 1 - i];
    }
    reversed[n] = '\0';
    return reversed;
}

// Reverse string in-place by swapping characters
void reverse_string_inplace(char *str) {
    if (!str) return;
    int n = string_length(str);
    for (int i = 0; i < n / 2; ++i) {
        // Swap characters
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) input = argv[1];
    else {
        static char buf[1024];
        printf("Enter a string: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    // Method 1: Create reversed copy
    char *reversed = reverse_string(input);
    if (reversed) {
        printf("Original: \"%s\"\n", input);
        printf("Reversed (copy): \"%s\"\n", reversed);
        free(reversed);
    }

    // Method 2: Reverse in-place on a copy
    int len = string_length(input);
    char *copy = malloc((size_t)len + 1);
    if (copy) {
        for (int i = 0; i < len + 1; ++i) {
            copy[i] = input[i];
        }
        reverse_string_inplace(copy);
        printf("Reversed (in-place): \"%s\"\n", copy);
        free(copy);
    }

    return 0;
}
