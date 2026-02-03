#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotate_left(char *s, int n) {
    int len = strlen(s);
    if (len == 0) return;
    n = n % len;
    if (n < 0) n += len;

    char temp[1024];
    
    strcpy(temp, s + n);
    strncat(temp, s, n);
    temp[len] = '\0';
    strcpy(s, temp);
}

int main(int argc, char *argv[]) {
    char str[1024];
    int n;

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin))
        return 0;

    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        printf("Enter number of positions to rotate left: ");
        if (scanf("%d", &n) != 1) return 0;
    }

    rotate_left(str, n);
    printf("Rotated string: %s\n", str);
    return 0;
}
