#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Find length of string
int string_length(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Toggle case: lowercase to uppercase and vice versa
char *toggle_case(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    for (int i = 0; i < n; ++i) {
        if (isupper((unsigned char)str[i])) {
            result[i] = tolower((unsigned char)str[i]);
        } else if (islower((unsigned char)str[i])) {
            result[i] = toupper((unsigned char)str[i]);
        } else {
            result[i] = str[i];  // Keep non-alphabetic characters as is
        }
    }
    result[n] = '\0';
    return result;
}

// Toggle case in-place (modifies the input string)
void toggle_case_inplace(char *str) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isupper((unsigned char)str[i])) {
            str[i] = tolower((unsigned char)str[i]);
        } else if (islower((unsigned char)str[i])) {
            str[i] = toupper((unsigned char)str[i]);
        }
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

    // Method 1: Create toggled copy
    char *toggled = toggle_case(input);
    if (toggled) {
        printf("Original: \"%s\"\n", input);
        printf("Toggled (copy): \"%s\"\n", toggled);
        free(toggled);
    }

    // Method 2: Toggle in-place on a copy
    int len = string_length(input);
    char *copy = malloc((size_t)len + 1);
    if (copy) {
        for (int i = 0; i < len + 1; ++i) {
            copy[i] = input[i];
        }
        toggle_case_inplace(copy);
        printf("Toggled (in-place): \"%s\"\n", copy);
        free(copy);
    }

    return 0;
}
