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

// Check if string is palindrome (case-insensitive, ignoring spaces and special chars)
int is_palindrome_flexible(const char *str) {
    if (!str) return 0;
    int n = string_length(str);
    int left = 0, right = n - 1;

    while (left < right) {
        // Skip non-alphanumeric on left
        while (left < right && !isalnum((unsigned char)str[left])) {
            left++;
        }
        // Skip non-alphanumeric on right
        while (left < right && !isalnum((unsigned char)str[right])) {
            right--;
        }
        // Compare characters (case-insensitive)
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

// Check if string is palindrome (strict: exact match)
int is_palindrome_strict(const char *str) {
    if (!str) return 0;
    int n = string_length(str);
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - 1 - i]) {
            return 0;
        }
    }
    return 1;
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

    printf("String: \"%s\"\n", input);

    // Strict palindrome check
    if (is_palindrome_strict(input)) {
        printf("Palindrome (strict): YES\n");
    } else {
        printf("Palindrome (strict): NO\n");
    }

    // Flexible palindrome check (ignore spaces, case-insensitive)
    if (is_palindrome_flexible(input)) {
        printf("Palindrome (flexible): YES\n");
    } else {
        printf("Palindrome (flexible): NO\n");
    }

    return 0;
}
