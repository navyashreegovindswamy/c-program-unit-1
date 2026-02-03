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

// Check if t is a rotation of s using substring method
// If t is a rotation of s, then t will always be a substring of s+s
int is_rotation_substring(const char *s, const char *t) {
    if (!s || !t) return 0;
    int s_len = string_length(s);
    int t_len = string_length(t);

    // Different lengths means not a rotation
    if (s_len != t_len) return 0;

    // Empty strings are rotations of each other
    if (s_len == 0) return 1;

    // Create s + s
    char *concatenated = malloc((size_t)(s_len * 2 + 1));
    if (!concatenated) return 0;

    for (int i = 0; i < s_len; ++i) {
        concatenated[i] = s[i];
        concatenated[s_len + i] = s[i];
    }
    concatenated[s_len * 2] = '\0';

    // Check if t is a substring of s+s
    int result = 0;
    for (int i = 0; i <= s_len; ++i) {
        int match = 1;
        for (int j = 0; j < t_len; ++j) {
            if (concatenated[i + j] != t[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            result = 1;
            break;
        }
    }

    free(concatenated);
    return result;
}

// Check if t is a rotation of s by finding rotation point
int is_rotation_verify(const char *s, const char *t) {
    if (!s || !t) return 0;
    int s_len = string_length(s);
    int t_len = string_length(t);

    if (s_len != t_len || s_len == 0) return 0;

    // Try each possible rotation point
    for (int rotation = 0; rotation < s_len; ++rotation) {
        int match = 1;
        for (int i = 0; i < s_len; ++i) {
            if (s[(rotation + i) % s_len] != t[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;
        }
    }
    return 0;
}

// Find the rotation point (how many positions rotated)
// Returns -1 if not a rotation
int find_rotation_point(const char *s, const char *t) {
    if (!s || !t) return -1;
    int s_len = string_length(s);
    int t_len = string_length(t);

    if (s_len != t_len || s_len == 0) return -1;

    for (int rotation = 0; rotation < s_len; ++rotation) {
        int match = 1;
        for (int i = 0; i < s_len; ++i) {
            if (s[(rotation + i) % s_len] != t[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return rotation;
        }
    }
    return -1;
}

// Print rotation details
void print_rotation_details(const char *s, const char *t) {
    int rotation_point = find_rotation_point(s, t);
    if (rotation_point >= 0) {
        printf("String s: \"%s\"\n", s);
        printf("String t: \"%s\"\n", t);
        printf("Result: YES, t is a rotation of s\n");
        printf("Rotation point: %d positions\n", rotation_point);
        if (rotation_point > 0) {
            printf("Explanation: Last %d characters of s moved to front\n", rotation_point);
        }
    } else {
        printf("String s: \"%s\"\n", s);
        printf("String t: \"%s\"\n", t);
        printf("Result: NO, t is not a rotation of s\n");
    }
}

int main(int argc, char **argv) {
    const char *s = NULL;
    const char *t = NULL;

    if (argc >= 3) {
        s = argv[1];
        t = argv[2];
    } else {
        static char buf_s[1024], buf_t[1024];
        printf("Enter first string (s): ");
        fflush(stdout);
        if (!fgets(buf_s, sizeof buf_s, stdin)) return 0;
        buf_s[strcspn(buf_s, "\r\n")] = '\0';

        printf("Enter second string (t): ");
        fflush(stdout);
        if (!fgets(buf_t, sizeof buf_t, stdin)) return 0;
        buf_t[strcspn(buf_t, "\r\n")] = '\0';

        s = buf_s;
        t = buf_t;
    }

    printf("\n");

    // Check using substring method
    printf("=== Method 1: Substring Check ===\n");
    if (is_rotation_substring(s, t)) {
        printf("YES, t is a rotation of s\n");
    } else {
        printf("NO, t is not a rotation of s\n");
    }

    printf("\n");

    // Check using verification method
    printf("=== Method 2: Verification ===\n");
    if (is_rotation_verify(s, t)) {
        printf("YES, t is a rotation of s\n");
    } else {
        printf("NO, t is not a rotation of s\n");
    }

    printf("\n");

    // Print detailed information
    printf("=== Details ===\n");
    print_rotation_details(s, t);

    return 0;
}
