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

// Check if a substring is a palindrome
int is_palindrome(const char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Find longest palindromic substring using expand around center approach
char *find_longest_palindrome_eac(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    if (n == 0) {
        char *result = malloc(1);
        result[0] = '\0';
        return result;
    }

    int max_start = 0, max_len = 1;

    // Expand around each center (odd length palindromes)
    for (int center = 0; center < n; ++center) {
        int left = center, right = center;
        while (left >= 0 && right < n && str[left] == str[right]) {
            int len = right - left + 1;
            if (len > max_len) {
                max_len = len;
                max_start = left;
            }
            left--;
            right++;
        }
    }

    // Expand around each center pair (even length palindromes)
    for (int center = 0; center < n - 1; ++center) {
        int left = center, right = center + 1;
        while (left >= 0 && right < n && str[left] == str[right]) {
            int len = right - left + 1;
            if (len > max_len) {
                max_len = len;
                max_start = left;
            }
            left--;
            right++;
        }
    }

    // Create result string
    char *result = malloc((size_t)max_len + 1);
    if (result) {
        for (int i = 0; i < max_len; ++i) {
            result[i] = str[max_start + i];
        }
        result[max_len] = '\0';
    }
    return result;
}

// Find longest palindromic substring using dynamic programming
char *find_longest_palindrome_dp(const char *str) {
    if (!str) return NULL;
    int n = string_length(str);
    if (n == 0) {
        char *result = malloc(1);
        result[0] = '\0';
        return result;
    }

    // Create DP table
    int **dp = malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        dp[i] = malloc((size_t)n * sizeof(int));
        memset(dp[i], 0, (size_t)n * sizeof(int));
    }

    int max_start = 0, max_len = 1;

    // Single characters are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Check for 2-character palindromes
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            max_len = 2;
            max_start = i;
        }
    }

    // Check for palindromes of length 3 and more
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                max_len = len;
                max_start = i;
            }
        }
    }

    // Free DP table
    for (int i = 0; i < n; ++i) {
        free(dp[i]);
    }
    free(dp);

    // Create result string
    char *result = malloc((size_t)max_len + 1);
    if (result) {
        for (int i = 0; i < max_len; ++i) {
            result[i] = str[max_start + i];
        }
        result[max_len] = '\0';
    }
    return result;
}

// Find and print all palindromes of length >= min_length
void print_all_palindromes(const char *str, int min_length) {
    if (!str) return;
    int n = string_length(str);

    printf("All palindromes of length >= %d in \"%s\":\n\n", min_length, str);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int len = j - i + 1;
            if (len >= min_length && is_palindrome(str, i, j)) {
                count++;
                printf("%d. \"", count);
                for (int k = i; k <= j; ++k) {
                    printf("%c", str[k]);
                }
                printf("\" (length: %d)\n", len);
            }
        }
    }

    if (count == 0) {
        printf("No palindromes found\n");
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

    // Find using expand around center
    char *longest_eac = find_longest_palindrome_eac(input);
    if (longest_eac) {
        printf("Longest palindrome (expand around center): \"%s\" (length: %zu)\n", 
               longest_eac, strlen(longest_eac));
        free(longest_eac);
    }

    printf("\n");

    // Find using dynamic programming
    char *longest_dp = find_longest_palindrome_dp(input);
    if (longest_dp) {
        printf("Longest palindrome (dynamic programming): \"%s\" (length: %zu)\n", 
               longest_dp, strlen(longest_dp));
        free(longest_dp);
    }

    printf("\n");

    // Print all palindromes of length >= 2
    print_all_palindromes(input, 2);

    return 0;
}
