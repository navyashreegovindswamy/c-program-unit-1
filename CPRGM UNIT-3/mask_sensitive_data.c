#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Mask phone number: keep only last 4 digits visible.
// e.g., "123-456-7890" -> "***-***-7890"
char *mask_phone(const char *phone) {
    if (!phone) return NULL;
    int n = (int)strlen(phone);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;
    strcpy(result, phone);

    // Find last 4 digits and mask everything else
    int digit_count = 0;
    int last_digit_idx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (isdigit((unsigned char)result[i])) {
            digit_count++;
            if (last_digit_idx == -1) last_digit_idx = i;
            if (digit_count == 4) {
                // Mask everything before this
                for (int j = 0; j < i; ++j) {
                    if (isdigit((unsigned char)result[j])) {
                        result[j] = '*';
                    }
                }
                break;
            }
        }
    }
    return result;
}

// Mask credit card: show only last 4 digits.
// e.g., "1234-5678-9012-3456" -> "****-****-****-3456"
char *mask_credit_card(const char *card) {
    if (!card) return NULL;
    int n = (int)strlen(card);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;
    strcpy(result, card);

    // Find last 4 digits and mask everything else
    int digit_count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (isdigit((unsigned char)result[i])) {
            digit_count++;
            if (digit_count > 4 && isdigit((unsigned char)result[i])) {
                result[i] = '*';
            }
        } else if (result[i] != '-' && result[i] != ' ') {
            // Keep non-digit, non-separator characters as is
            continue;
        }
    }

    // Mask all digits except last 4
    int visible = 0;
    for (int i = n - 1; i >= 0 && visible < 4; --i) {
        if (isdigit((unsigned char)result[i])) visible++;
    }
    visible = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (isdigit((unsigned char)result[i])) {
            visible++;
            if (visible > 4) result[i] = '*';
        }
    }
    return result;
}

// Mask SSN: show only last 4 digits.
// e.g., "123-45-6789" -> "***-**-6789"
char *mask_ssn(const char *ssn) {
    if (!ssn) return NULL;
    int n = (int)strlen(ssn);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;
    strcpy(result, ssn);

    int digit_count = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (isdigit((unsigned char)result[i])) {
            digit_count++;
            if (digit_count > 4) {
                result[i] = '*';
            }
        }
    }
    return result;
}

// Mask email: show only first letter and domain.
// e.g., "john.doe@example.com" -> "j***@example.com"
char *mask_email(const char *email) {
    if (!email) return NULL;
    const char *at = strchr(email, '@');
    if (!at) return NULL;

    int at_pos = (int)(at - email);
    int n = (int)strlen(email);
    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;

    // Keep first character
    result[0] = email[0];
    // Mask middle part
    for (int i = 1; i < at_pos; ++i) {
        result[i] = '*';
    }
    // Copy domain part
    strcpy(result + at_pos, at);
    return result;
}

// Mask generic string: show first and last char, mask middle.
// e.g., "HelloWorld" -> "H********d"
char *mask_generic(const char *str) {
    if (!str) return NULL;
    int n = (int)strlen(str);
    if (n <= 2) {
        char *result = malloc((size_t)n + 1);
        if (!result) return NULL;
        strcpy(result, str);
        return result;
    }

    char *result = malloc((size_t)n + 1);
    if (!result) return NULL;
    result[0] = str[0];
    for (int i = 1; i < n - 1; ++i) {
        result[i] = '*';
    }
    result[n - 1] = str[n - 1];
    result[n] = '\0';
    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <type> <data>\n", argv[0]);
        printf("Types: phone, card, ssn, email, generic\n");
        printf("Examples:\n");
        printf("  %s phone \"123-456-7890\"\n", argv[0]);
        printf("  %s card \"1234-5678-9012-3456\"\n", argv[0]);
        printf("  %s ssn \"123-45-6789\"\n", argv[0]);
        printf("  %s email \"john.doe@example.com\"\n", argv[0]);
        printf("  %s generic \"HelloWorld\"\n", argv[0]);
        return 0;
    }

    const char *type = argv[1];
    const char *data = argv[2];
    char *masked = NULL;

    if (strcmp(type, "phone") == 0) {
        masked = mask_phone(data);
        printf("Phone (masked): %s\n", masked);
    } else if (strcmp(type, "card") == 0) {
        masked = mask_credit_card(data);
        printf("Card (masked): %s\n", masked);
    } else if (strcmp(type, "ssn") == 0) {
        masked = mask_ssn(data);
        printf("SSN (masked): %s\n", masked);
    } else if (strcmp(type, "email") == 0) {
        masked = mask_email(data);
        printf("Email (masked): %s\n", masked);
    } else if (strcmp(type, "generic") == 0) {
        masked = mask_generic(data);
        printf("Generic (masked): %s\n", masked);
    } else {
        printf("Unknown type: %s\n", type);
        if (masked) free(masked);
        return 1;
    }

    if (masked) free(masked);
    return 0;
}
