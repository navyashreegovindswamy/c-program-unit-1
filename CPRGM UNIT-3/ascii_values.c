#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    printf("\nASCII values of each character:\n");
    printf("Character\tASCII Value\n");
    printf("------------------------\n");
    
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c\t\t%d\n", str[i], (int)str[i]);
    }
    
    return 0;
}
