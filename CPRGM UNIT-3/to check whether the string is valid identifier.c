#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(char str[]) {
    if (strlen(str) == 0)
        return 0;

    if (!isalpha(str[0]) && str[0] != '_')
        return 0;
    
    
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    
    return 1;
}

int main() {
    char str[100];
    
    printf("Enter a string to check if it is a valid identifier: ");
    fgets(str, sizeof(str), stdin);
    
    
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    if (isValidIdentifier(str))
        printf("\"%s\" is a VALID identifier.\n", str);
    else
        printf("\"%s\" is NOT a valid identifier.\n", str);
    
    return 0;
}
