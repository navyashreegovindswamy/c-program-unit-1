#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int is_valid_local_char(char c) {
    return isalnum((unsigned char)c) || c == '.' || c == '_' || c == '+' || c == '-' || c == '%';
}

static int is_valid_domain_char(char c) {
    return isalnum((unsigned char)c) || c == '.' || c == '-';
}

int is_valid_email(const char *s) {
    if (!s) return 0;
    int n = (int)strlen(s);
    if (n == 0) return 0;

    // no whitespace
    for (int i = 0; i < n; ++i) if (isspace((unsigned char)s[i])) return 0;

    const char *at = strchr(s, '@');
    if (!at) return 0;
    if (strchr(at + 1, '@')) return 0; // more than one '@'

    int local_len = (int)(at - s);
    int domain_len = n - local_len - 1;
    if (local_len < 1 || domain_len < 3) return 0;

    // Local checks
    if (s[0] == '.' || s[local_len - 1] == '.') return 0;
    for (int i = 0; i < local_len; ++i) {
        char c = s[i];
        if (!is_valid_local_char(c)) return 0;
        if (c == '.' && i + 1 < local_len && s[i + 1] == '.') return 0;
    }

    // Domain checks
    const char *d = at + 1;
    if (d[0] == '.' || d[domain_len - 1] == '.') return 0;
    if (d[0] == '-' || d[domain_len - 1] == '-') return 0;

    int label_len = 0;
    int dot_found = 0;
    for (int i = 0; i < domain_len; ++i) {
        char c = d[i];
        if (!is_valid_domain_char(c)) return 0;
        if (c == '.') {
            if (label_len == 0) return 0; 
            dot_found = 1;
            label_len = 0;
        } else {
            if (c == '-' && label_len == 0) return 0; 
            label_len++;
        }
    }
    if (label_len == 0) return 0;
    if (!dot_found) return 0; 
    return 1;
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) input = argv[1];
    else {
        static char buf[1024];
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    if (is_valid_email(input)) printf("Valid\n");
    else printf("Invalid\n");
    return 0;
}
