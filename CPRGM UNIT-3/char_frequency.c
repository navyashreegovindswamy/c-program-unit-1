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

// Count frequency of each character in a string
void count_char_frequency(const char *str) {
    if (!str) return;

    int n = string_length(str);
    int freq[256] = {0};  // Frequency array for all ASCII characters

    // Count frequencies
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        freq[c]++;
    }

    // Display results
    printf("Character Frequency:\n");
    printf("%-10s %s\n", "Character", "Count");
    printf("%-10s %s\n", "---------", "-----");

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            char c = (char)i;
            if (c == ' ') {
                printf("%-10s %d\n", "[space]", freq[i]);
            } else if (c == '\t') {
                printf("%-10s %d\n", "[tab]", freq[i]);
            } else if (c == '\n') {
                printf("%-10s %d\n", "[newline]", freq[i]);
            } else if (c < 32 || c > 126) {
                printf("%-10s %d\n", "[control]", freq[i]);
            } else {
                printf("'%c'%-7s %d\n", c, "", freq[i]);
            }
        }
    }
}

// Alternative: Count only alphanumeric characters (case-insensitive)
void count_alphanum_frequency_ci(const char *str) {
    if (!str) return;

    int n = string_length(str);
    int freq[256] = {0};

    // Count frequencies (case-insensitive for letters)
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (c >= 'a' && c <= 'z') {
            freq[c]++;
        } else if (c >= 'A' && c <= 'Z') {
            freq[c - 'A' + 'a']++;  // Convert to lowercase
        } else if (c >= '0' && c <= '9') {
            freq[c]++;
        }
    }

    // Display results
    printf("Alphanumeric Frequency (case-insensitive):\n");
    printf("%-10s %s\n", "Character", "Count");
    printf("%-10s %s\n", "---------", "-----");

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            char c = (char)i;
            if (c >= 'a' && c <= 'z') {
                printf("'%c'%-7s %d\n", c, "", freq[i]);
            } else if (c >= '0' && c <= '9') {
                printf("'%c'%-7s %d\n", c, "", freq[i]);
            }
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

    printf("String: \"%s\"\n\n", input);

    // Show all characters
    count_char_frequency(input);

    printf("\n");

    // Show alphanumeric only (case-insensitive)
    count_alphanum_frequency_ci(input);

    return 0;
}
