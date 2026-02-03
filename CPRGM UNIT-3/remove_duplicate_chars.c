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

// Remove duplicates and maintain original order
char *remove_duplicates(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    int seen[256] = {0};  // Track which characters have been seen
    int j = 0;

    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}

// Remove duplicates in-place
void remove_duplicates_inplace(char *str) {
    if (!str) return;
    int seen[256] = {0};
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Remove duplicates (case-insensitive)
char *remove_duplicates_ci(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    int seen[256] = {0};
    int j = 0;

    for (int i = 0; i < n; ++i) {
        char c = str[i];
        unsigned char key = (unsigned char)c;
        
        // Convert to lowercase for comparison
        if (c >= 'A' && c <= 'Z') {
            key = (unsigned char)(c - 'A' + 'a');
        }

        if (!seen[key]) {
            seen[key] = 1;
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}

// Count unique characters
int count_unique_chars(const char *str) {
    if (!str) return 0;
    int seen[256] = {0};
    int count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (!seen[c]) {
            seen[c] = 1;
            count++;
        }
    }
    return count;
}

// Print duplicate characters with their first and second occurrence indices
void print_duplicates(const char *str) {
    if (!str) return;
    int n = string_length(str);
    int seen[256] = {-1};  // Store first occurrence index

    printf("Duplicate characters in \"%s\":\n", str);
    int found = 0;

    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (seen[c] == -1) {
            seen[c] = i;
        } else {
            printf("'%c' - first at index %d, second at index %d\n", str[i], seen[c], i);
            found = 1;
        }
    }
    if (!found) {
        printf("No duplicates found\n");
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

    // Count unique characters
    int unique = count_unique_chars(input);
    int total = string_length(input);
    printf("Total characters: %d\n", total);
    printf("Unique characters: %d\n", total - unique);
    printf("\n");

    // Case-sensitive removal
    char *no_dup_cs = remove_duplicates(input);
    if (no_dup_cs) {
        printf("Without duplicates (case-sensitive): \"%s\"\n", no_dup_cs);
        free(no_dup_cs);
    }

    printf("\n");

    // Case-insensitive removal
    char *no_dup_ci = remove_duplicates_ci(input);
    if (no_dup_ci) {
        printf("Without duplicates (case-insensitive): \"%s\"\n", no_dup_ci);
        free(no_dup_ci);
    }

    printf("\n");

    // Show duplicates
    print_duplicates(input);

    return 0;
}
