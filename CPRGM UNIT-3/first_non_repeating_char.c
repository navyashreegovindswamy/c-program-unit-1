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

// Find first non-repeating character (case-sensitive)
char find_first_non_repeating(const char *str) {
    if (!str) return '\0';
    int n = string_length(str);
    int freq[256] = {0};

    // Count frequency of each character
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        freq[c]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (freq[c] == 1) {
            return str[i];
        }
    }

    return '\0';  // No non-repeating character found
}

// Find first non-repeating character (case-insensitive, ignoring spaces)
char find_first_non_repeating_ci(const char *str) {
    if (!str) return '\0';
    int n = string_length(str);
    int freq[256] = {0};

    // Count frequency of each character (case-insensitive, skip spaces)
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (c == ' ') continue;  // Skip spaces
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        freq[(unsigned char)c]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < n; ++i) {
        char c = str[i];
        if (c == ' ') continue;  // Skip spaces
        char lower_c = c;
        if (lower_c >= 'A' && lower_c <= 'Z') lower_c = lower_c - 'A' + 'a';
        if (freq[(unsigned char)lower_c] == 1) {
            return str[i];
        }
    }

    return '\0';  // No non-repeating character found
}

// Find all non-repeating characters
void find_all_non_repeating(const char *str) {
    if (!str) return;
    int n = string_length(str);
    int freq[256] = {0};

    // Count frequency
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        freq[c]++;
    }

    // Print all non-repeating characters
    printf("All non-repeating characters in \"%s\":\n", str);
    int found = 0;
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (freq[c] == 1) {
            printf("'%c' at index %d\n", str[i], i);
            found = 1;
        }
    }
    if (!found) {
        printf("No non-repeating characters found\n");
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

    // Case-sensitive search
    char first_cs = find_first_non_repeating(input);
    printf("First non-repeating character (case-sensitive):\n");
    if (first_cs != '\0') {
        printf("Result: '%c'\n", first_cs);
    } else {
        printf("Result: Not found\n");
    }

    printf("\n");

    // Case-insensitive search
    char first_ci = find_first_non_repeating_ci(input);
    printf("First non-repeating character (case-insensitive, ignoring spaces):\n");
    if (first_ci != '\0') {
        printf("Result: '%c'\n", first_ci);
    } else {
        printf("Result: Not found\n");
    }

    printf("\n");

    // Show all non-repeating characters
    find_all_non_repeating(input);

    return 0;
}
