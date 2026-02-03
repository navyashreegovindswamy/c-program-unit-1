#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Password strength levels
enum strength_level {
    WEAK = 0,
    FAIR,
    GOOD,
    STRONG,
    VERY_STRONG
};

const char *strength_names[] = {"WEAK", "FAIR", "GOOD", "STRONG", "VERY_STRONG"};

// Check password strength based on multiple rules.
// Rules enforced:
// - Minimum length 8 characters (+1 strength if >= 12, +1 if >= 16)
// - Contains uppercase letter (+1 strength)
// - Contains lowercase letter (+1 strength)
// - Contains digit (+1 strength)
// - Contains special character (+1 strength)
// - No spaces
enum strength_level check_password_strength(const char *pass) {
    if (!pass) return WEAK;
    int n = (int)strlen(pass);
    int score = 0;

    // Rule 1: No spaces
    for (int i = 0; i < n; ++i) {
        if (isspace((unsigned char)pass[i])) return WEAK;
    }

    // Rule 2: Minimum length
    if (n >= 8) score++;
    if (n >= 12) score++;
    if (n >= 16) score++;

    // Rule 3: Has uppercase
    int has_upper = 0;
    for (int i = 0; i < n; ++i) {
        if (isupper((unsigned char)pass[i])) {
            has_upper = 1;
            break;
        }
    }
    if (has_upper) score++;

    // Rule 4: Has lowercase
    int has_lower = 0;
    for (int i = 0; i < n; ++i) {
        if (islower((unsigned char)pass[i])) {
            has_lower = 1;
            break;
        }
    }
    if (has_lower) score++;

    // Rule 5: Has digit
    int has_digit = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit((unsigned char)pass[i])) {
            has_digit = 1;
            break;
        }
    }
    if (has_digit) score++;

    // Rule 6: Has special character
    int has_special = 0;
    for (int i = 0; i < n; ++i) {
        char c = pass[i];
        if (!isalnum((unsigned char)c)) {
            has_special = 1;
            break;
        }
    }
    if (has_special) score++;

    // Map score to strength level
    if (score < 3) return WEAK;
    if (score < 4) return FAIR;
    if (score < 5) return GOOD;
    if (score < 6) return STRONG;
    return VERY_STRONG;
}

void print_feedback(const char *pass, enum strength_level level) {
    printf("Password: %s\n", pass);
    printf("Strength: %s\n", strength_names[level]);
    printf("Details:\n");
    printf("  - Length: %zu chars\n", strlen(pass));
    
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    for (size_t i = 0; i < strlen(pass); ++i) {
        if (isupper((unsigned char)pass[i])) has_upper = 1;
        if (islower((unsigned char)pass[i])) has_lower = 1;
        if (isdigit((unsigned char)pass[i])) has_digit = 1;
        if (!isalnum((unsigned char)pass[i])) has_special = 1;
    }

    printf("  - Uppercase: %s\n", has_upper ? "Yes" : "No");
    printf("  - Lowercase: %s\n", has_lower ? "Yes" : "No");
    printf("  - Digit: %s\n", has_digit ? "Yes" : "No");
    printf("  - Special char: %s\n", has_special ? "Yes" : "No");
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) input = argv[1];
    else {
        static char buf[1024];
        printf("Enter password: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    enum strength_level level = check_password_strength(input);
    print_feedback(input, level);
    return 0;
}
