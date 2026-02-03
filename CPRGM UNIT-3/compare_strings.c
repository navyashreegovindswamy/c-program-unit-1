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

// Compare two strings manually without using strcmp()
// Returns: 0 if equal, < 0 if str1 < str2, > 0 if str1 > str2
int compare_strings(const char *str1, const char *str2) {
    if (!str1 && !str2) return 0;
    if (!str1) return -1;
    if (!str2) return 1;

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }

    // Handle different lengths
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;  // Equal
    } else if (str1[i] == '\0') {
        return -1;  // str1 is shorter (less)
    } else {
        return 1;   // str2 is shorter (str1 is greater)
    }
}

// Compare two strings case-insensitively
// Returns: 0 if equal, < 0 if str1 < str2, > 0 if str1 > str2
int compare_strings_ci(const char *str1, const char *str2) {
    if (!str1 && !str2) return 0;
    if (!str1) return -1;
    if (!str2) return 1;

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];

        // Convert to lowercase for comparison
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 - 'A' + 'a';
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 - 'A' + 'a';

        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return 1;
        }
        i++;
    }

    // Handle different lengths
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;  // Equal
    } else if (str1[i] == '\0') {
        return -1;  // str1 is shorter (less)
    } else {
        return 1;   // str2 is shorter (str1 is greater)
    }
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

    // Case-sensitive comparison
    int result_case_sensitive = compare_strings(str1, str2);
    printf("String 1: \"%s\"\n", str1);
    printf("String 2: \"%s\"\n\n", str2);

    printf("Case-Sensitive Comparison:\n");
    if (result_case_sensitive == 0) {
        printf("Result: EQUAL\n");
    } else if (result_case_sensitive < 0) {
        printf("Result: String 1 < String 2\n");
    } else {
        printf("Result: String 1 > String 2\n");
    }

    printf("\n");

    // Case-insensitive comparison
    int result_case_insensitive = compare_strings_ci(str1, str2);
    printf("Case-Insensitive Comparison:\n");
    if (result_case_insensitive == 0) {
        printf("Result: EQUAL\n");
    } else if (result_case_insensitive < 0) {
        printf("Result: String 1 < String 2\n");
    } else {
        printf("Result: String 1 > String 2\n");
    }

    return 0;
}
