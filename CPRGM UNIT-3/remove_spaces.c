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

// Remove all spaces from string and return new string
char *remove_spaces(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (!isspace((unsigned char)str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}

// Remove spaces in-place (modifies the input string)
void remove_spaces_inplace(char *str) {
    if (!str) return;
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace((unsigned char)str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Count spaces in a string
int count_spaces(const char *str) {
    if (!str) return 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isspace((unsigned char)str[i])) {
            count++;
        }
    }
    return count;
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

    int spaces = count_spaces(input);
    char *no_spaces = remove_spaces(input);

    if (no_spaces) {
        printf("Original: \"%s\"\n", input);
        printf("Spaces removed: \"%s\"\n", no_spaces);
        printf("Spaces found: %d\n", spaces);
        free(no_spaces);
    }

    return 0;
}
