#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int lps_length(const char *s) {
    int n = (int)strlen(s);
    if (n == 0) return 0;
    char *t = (char *)malloc((size_t)n + 1);
    if (!t) return 0;
    for (int i = 0; i < n; ++i) t[i] = s[n - 1 - i];
    t[n] = '\0';

    int *prev = (int *)calloc((size_t)n + 1, sizeof(int));
    int *curr = (int *)calloc((size_t)n + 1, sizeof(int));
    if (!prev || !curr) {
        free(t); free(prev); free(curr);
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) curr[j] = prev[j - 1] + 1;
            else curr[j] = prev[j] > curr[j - 1] ? prev[j] : curr[j - 1];
        }
        int *tmp = prev; prev = curr; curr = tmp;
        memset(curr, 0, (n + 1) * sizeof(int));
    }

    int res = prev[n];
    free(prev); free(curr); free(t);
    return res;
}

int main(int argc, char **argv) {
    const char *input = NULL;
    char buf[10005];
    if (argc > 1) input = argv[1];
    else {
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    int n = (int)strlen(input);
    int lps = lps_length(input);
    int min_del = n - lps;
    printf("%d\n", min_del);
    return 0;
}
