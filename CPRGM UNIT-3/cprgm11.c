#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256

int main() {
    char str[1000];
    int freq[MAX_CHARS] = {0};
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    for (size_t i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
    }
    printf("\nCharacter Frequencies:\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            if (isprint(i)) {
                printf("'%c' : %d\n", i, freq[i]);
            } else {
                printf("'0x%02X' : %d\n", i, freq[i]);
            }
        }
    }

    return 0;
}