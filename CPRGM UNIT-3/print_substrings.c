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

// Print all substrings of a given string
void print_all_substrings(const char *str) {
    if (!str) return;
    int n = string_length(str);

    printf("All substrings of \"%s\":\n\n", str);

    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            // Print substring from index i to j-1
            printf("\"");
            for (int k = i; k < j; ++k) {
                printf("%c", str[k]);
            }
            printf("\"\n");
        }
    }
}

// Print all substrings and count them
int count_and_print_substrings(const char *str) {
    if (!str) return 0;
    int n = string_length(str);
    int count = 0;

    printf("All substrings of \"%s\":\n\n", str);

    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            count++;
            printf("%d. \"", count);
            for (int k = i; k < j; ++k) {
                printf("%c", str[k]);
            }
            printf("\"\n");
        }
    }
    return count;
}

// Print substrings of a specific length
void print_substrings_of_length(const char *str, int length) {
    if (!str) return;
    int n = string_length(str);

    if (length > n || length <= 0) {
        printf("No substrings of length %d exist\n", length);
        return;
    }

    printf("Substrings of length %d in \"%s\":\n\n", length, str);
    int count = 0;

    for (int i = 0; i <= n - length; ++i) {
        count++;
        printf("%d. \"", count);
        for (int j = i; j < i + length; ++j) {
            printf("%c", str[j]);
        }
        printf("\"\n");
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

    // Print all substrings with count
    int total = count_and_print_substrings(input);
    printf("\nTotal substrings: %d\n", total);

    // Print substrings of specific lengths for examples
    printf("\n");
    int n = string_length(input);
    if (n > 0) {
        print_substrings_of_length(input, 1);
        printf("\n");
    }
    if (n > 1) {
        print_substrings_of_length(input, 2);
        printf("\n");
    }
    if (n > 2) {
        print_substrings_of_length(input, 3);
    }

    return 0;
}
