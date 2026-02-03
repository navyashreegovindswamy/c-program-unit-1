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

// Check if two strings are anagrams (case-insensitive, ignoring spaces)
int are_anagrams_flexible(const char *str1, const char *str2) {
    if (!str1 || !str2) return 0;

    int freq1[256] = {0};
    int freq2[256] = {0};

    // Count characters in first string (ignoring spaces, case-insensitive)
    for (int i = 0; str1[i] != '\0'; ++i) {
        char c = str1[i];
        if (!isspace((unsigned char)c)) {
            if (isupper((unsigned char)c)) c = tolower((unsigned char)c);
            freq1[(unsigned char)c]++;
        }
    }

    // Count characters in second string (ignoring spaces, case-insensitive)
    for (int i = 0; str2[i] != '\0'; ++i) {
        char c = str2[i];
        if (!isspace((unsigned char)c)) {
            if (isupper((unsigned char)c)) c = tolower((unsigned char)c);
            freq2[(unsigned char)c]++;
        }
    }

    // Compare frequencies
    for (int i = 0; i < 256; ++i) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

// Check if two strings are anagrams (strict: exact case match)
int are_anagrams_strict(const char *str1, const char *str2) {
    if (!str1 || !str2) return 0;

    int freq1[256] = {0};
    int freq2[256] = {0};

    // Count characters in first string
    for (int i = 0; str1[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str1[i];
        freq1[c]++;
    }

    // Count characters in second string
    for (int i = 0; str2[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str2[i];
        freq2[c]++;
    }

    // Compare frequencies
    for (int i = 0; i < 256; ++i) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    const char *str1 = NULL;
    const char *str2 = NULL;

    if (argc >= 3) {
        str1 = argv[1];
        str2 = argv[2];
    } else {
        static char buf1[1024], buf2[1024];
        printf("Enter first string: ");
        fflush(stdout);
        if (!fgets(buf1, sizeof buf1, stdin)) return 0;
        buf1[strcspn(buf1, "\r\n")] = '\0';

        printf("Enter second string: ");
        fflush(stdout);
        if (!fgets(buf2, sizeof buf2, stdin)) return 0;
        buf2[strcspn(buf2, "\r\n")] = '\0';

        str1 = buf1;
        str2 = buf2;
    }

    printf("String 1: \"%s\"\n", str1);
    printf("String 2: \"%s\"\n\n", str2);

    // Strict comparison
    printf("Strict Anagram Check (case-sensitive, including spaces):\n");
    if (are_anagrams_strict(str1, str2)) {
        printf("Result: YES, they are anagrams\n");
    } else {
        printf("Result: NO, they are not anagrams\n");
    }

    printf("\n");

    // Flexible comparison
    printf("Flexible Anagram Check (case-insensitive, ignoring spaces):\n");
    if (are_anagrams_flexible(str1, str2)) {
        printf("Result: YES, they are anagrams\n");
    } else {
        printf("Result: NO, they are not anagrams\n");
    }

    return 0;
}
