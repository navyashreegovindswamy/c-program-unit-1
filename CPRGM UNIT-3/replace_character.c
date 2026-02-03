#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find length of string
int string_length(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Replace all occurrences of a character and return new string
char *replace_character(const char *str, char find, char replace) {
    if (!str) return NULL;
    int n = string_length(str);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    for (int i = 0; i < n; ++i) {
        if (str[i] == find) {
            result[i] = replace;
        } else {
            result[i] = str[i];
        }
    }
    result[n] = '\0';
    return result;
}

// Replace all occurrences of a character in-place
void replace_character_inplace(char *str, char find, char replace) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }
}

// Count occurrences of a character in a string
int count_occurrences(const char *str, char ch) {
    if (!str) return 0;
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    const char *input = NULL;
    char find_char = '\0';
    char replace_char = '\0';

    if (argc >= 4) {
        input = argv[1];
        find_char = argv[2][0];
        replace_char = argv[3][0];
    } else if (argc == 3) {
        input = argv[1];
        find_char = argv[2][0];
        printf("Enter replacement character: ");
        fflush(stdout);
        replace_char = getchar();
    } else {
        static char buf[1024];
        printf("Enter a string: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;

        printf("Enter character to find: ");
        fflush(stdout);
        find_char = getchar();
        getchar();  // consume newline

        printf("Enter replacement character: ");
        fflush(stdout);
        replace_char = getchar();
    }

    if (find_char == '\0' || replace_char == '\0') {
        printf("Invalid character input\n");
        return 1;
    }

    int occurrences = count_occurrences(input, find_char);
    char *result = replace_character(input, find_char, replace_char);

    if (result) {
        printf("Original: \"%s\"\n", input);
        printf("Find: '%c'\n", find_char);
        printf("Replace with: '%c'\n", replace_char);
        printf("Occurrences found: %d\n", occurrences);
        printf("Result: \"%s\"\n", result);
        free(result);
    }

    return 0;
}
