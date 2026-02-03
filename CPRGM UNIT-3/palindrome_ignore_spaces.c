#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    char filtered[200];
    int i, k = 0;

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin))
        return 0;
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            filtered[k++] = tolower((unsigned char)str[i]);
        }
    }
    filtered[k] = '\0';

    int left = 0, right = k - 1;
    int isPalindrome = 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("\"%s\" is a palindrome (ignoring spaces).\n", str);
    else
        printf("\"%s\" is NOT a palindrome (ignoring spaces).\n", str);

    return 0;
}
