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

// Count valid words (containing only alphabetic characters)
int count_valid_words(const char *str) {
    if (!str) return 0;
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha((unsigned char)str[i])) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return count;
}

// Print all valid words and count them
int print_valid_words(const char *str) {
    if (!str) return 0;
    int count = 0;
    int in_word = 0;
    char word[256];
    int word_idx = 0;

    printf("Valid words in \"%s\":\n\n", str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (isalpha((unsigned char)str[i])) {
            if (!in_word) {
                in_word = 1;
                word_idx = 0;
            }
            word[word_idx++] = str[i];
        } else {
            if (in_word) {
                word[word_idx] = '\0';
                count++;
                printf("%d. \"%s\"\n", count, word);
                in_word = 0;
            }
        }
    }

    // Handle last word if string ends with a letter
    if (in_word) {
        word[word_idx] = '\0';
        count++;
        printf("%d. \"%s\"\n", count, word);
    }

    return count;
}

// Count statistics: valid words, invalid tokens, total tokens
void print_statistics(const char *str) {
    if (!str) return;
    int valid_words = 0;
    int in_word = 0;
    int invalid_tokens = 0;
    int digits = 0;
    int special_chars = 0;
    int spaces = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        char c = str[i];
        if (isalpha((unsigned char)c)) {
            if (!in_word) {
                valid_words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
            if (isspace((unsigned char)c)) {
                spaces++;
            } else if (isdigit((unsigned char)c)) {
                digits++;
            } else {
                special_chars++;
            }
        }
    }

    printf("Statistics for \"%s\":\n", str);
    printf("Total length: %zu characters\n", strlen(str));
    printf("Valid words (alphabetic only): %d\n", valid_words);
    printf("Spaces: %d\n", spaces);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special_chars);
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) {
        // Concatenate all arguments
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

    printf("String: \"%s\"\n\n", input);

    // Print statistics
    print_statistics(input);
    printf("\n");

    // Count valid words
    int count = count_valid_words(input);
    printf("Total valid words: %d\n\n", count);

    // Print all valid words
    print_valid_words(input);

    return 0;
}
