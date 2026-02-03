#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char str[1024];
    int shift;

    if (argc > 1) {
        shift = atoi(argv[1]);
    } else {
        printf("Enter shift (positive for encrypt, negative for decrypt): ");
        if (scanf("%d", &shift) != 1) return 0;
        getchar();
    }

    if (!fgets(str, sizeof(str), stdin)) return 0;
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

    int n = strlen(str);
    char out[1024];

    for (int i = 0; i < n; i++) {
        char c = str[i];
        if (isupper((unsigned char)c)) {
            out[i] = (char)('A' + ( (c - 'A' + shift) % 26 + 26) % 26);
        } else if (islower((unsigned char)c)) {
            out[i] = (char)('a' + ( (c - 'a' + shift) % 26 + 26) % 26);
        } else {
            out[i] = c;
        }
    }
    out[n] = '\0';

    printf("Encrypted output: %s\n", out);
    return 0;
}
