#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int vowels;
    int consonants;
    int digits;
    int spaces;
} CharCount;

// Count vowels, consonants, digits, and spaces in a string
CharCount count_characters(const char *str) {
    CharCount result = {0, 0, 0, 0};
    if (!str) return result;

    for (int i = 0; str[i] != '\0'; ++i) {
        char c = str[i];

        if (isspace((unsigned char)c)) {
            result.spaces++;
        } else if (isdigit((unsigned char)c)) {
            result.digits++;
        } else if (isalpha((unsigned char)c)) {
            char lower = tolower((unsigned char)c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                result.vowels++;
            } else {
                result.consonants++;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) {
        // Concatenate all command-line arguments as a single string
        static char buf[2048];
        buf[0] = '\0';
        for (int i = 1; i < argc; ++i) {
            if (i > 1) strcat(buf, " ");
            strcat(buf, argv[i]);
        }
        input = buf;
    } else {
        // Read from stdin
        static char buf[2048];
        printf("Enter a string: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    CharCount count = count_characters(input);

    printf("String: \"%s\"\n", input);
    printf("Vowels: %d\n", count.vowels);
    printf("Consonants: %d\n", count.consonants);
    printf("Digits: %d\n", count.digits);
    printf("Spaces: %d\n", count.spaces);

    return 0;
}
