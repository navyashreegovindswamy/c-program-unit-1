#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    // Replace vowels with *
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || 
            str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || 
            str[i] == 'O' || str[i] == 'U') {
            str[i] = '*';
        }
    }
    
    printf("String after replacing vowels: %s\n", str);
    
    return 0;
}
