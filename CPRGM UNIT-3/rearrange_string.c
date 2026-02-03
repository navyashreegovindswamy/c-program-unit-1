#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rearrange_no_adjacent(const char *s) {
    if (!s) return NULL;
    int n = (int)strlen(s);
    char *res = malloc((size_t)n + 1);
    if (!res) return NULL;
    if (n == 0) {
        res[0] = '\0';
        return res;
    }

    int freq[256] = {0};
    for (int i = 0; i < n; ++i) freq[(unsigned char)s[i]]++;

    for (int c = 0; c < 256; ++c) {
        if (freq[c] > (n + 1) / 2) {
            free(res);
            return NULL; 
        }
    }

    int prev = -1;
    for (int pos = 0; pos < n; ++pos) {
        int first = -1;
        for (int c = 0; c < 256; ++c) {
            if (freq[c] <= 0) continue;
            if (c == prev) continue;
            if (first == -1 || freq[c] > freq[first]) first = c;
        }
        if (first == -1) { 
            free(res);
            return NULL;
        }
        res[pos] = (char)first;
        freq[first]--;
        prev = first;
    }
    res[n] = '\0';
    return res;
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

    char *out = rearrange_no_adjacent(input);
    if (!out) {
        printf("Not possible\n");
        return 0;
    }
    printf("%s\n", out);
    free(out);
    return 0;
}
