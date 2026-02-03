#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char domain[256];
    int count;
} DomainFreq;

// Extract domain from email address (part after '@')
// Returns pointer to domain or NULL if no '@' found.
const char *extract_domain(const char *email) {
    const char *at = strchr(email, '@');
    return at ? at + 1 : NULL;
}

// Find or add domain to frequency array, return index.
int find_or_add_domain(DomainFreq *freqs, int *count, const char *domain) {
    for (int i = 0; i < *count; ++i) {
        if (strcmp(freqs[i].domain, domain) == 0) {
            return i;
        }
    }
    // New domain
    if (*count < 100) {
        strcpy(freqs[*count].domain, domain);
        freqs[*count].count = 0;
        return (*count)++;
    }
    return -1;
}

// Compare function for qsort: sort by frequency (descending).
int compare_freq(const void *a, const void *b) {
    const DomainFreq *da = (const DomainFreq *)a;
    const DomainFreq *db = (const DomainFreq *)b;
    if (db->count != da->count) return db->count - da->count;
    return strcmp(da->domain, db->domain);
}

int main(int argc, char **argv) {
    DomainFreq freqs[100];
    int freq_count = 0;

    if (argc > 1) {
        // Process command-line arguments as emails
        for (int i = 1; i < argc; ++i) {
            const char *domain = extract_domain(argv[i]);
            if (domain && strlen(domain) > 0) {
                int idx = find_or_add_domain(freqs, &freq_count, domain);
                if (idx >= 0) freqs[idx].count++;
            }
        }
    } else {
        // Read from stdin (one email per line)
        static char buf[1024];
        while (fgets(buf, sizeof buf, stdin)) {
            buf[strcspn(buf, "\r\n")] = '\0';
            if (strlen(buf) == 0) break;
            const char *domain = extract_domain(buf);
            if (domain && strlen(domain) > 0) {
                int idx = find_or_add_domain(freqs, &freq_count, domain);
                if (idx >= 0) freqs[idx].count++;
            }
        }
    }

    if (freq_count == 0) {
        printf("No valid domains found\n");
        return 0;
    }

    // Sort by frequency descending
    qsort(freqs, (size_t)freq_count, sizeof(DomainFreq), compare_freq);

    // Print results
    printf("Domain Frequency:\n");
    printf("%-30s %s\n", "Domain", "Count");
    printf("%-30s %s\n", "---", "---");
    for (int i = 0; i < freq_count; ++i) {
        printf("%-30s %d\n", freqs[i].domain, freqs[i].count);
    }

    return 0;
}
