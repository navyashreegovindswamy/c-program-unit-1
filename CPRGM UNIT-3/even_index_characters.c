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
    
    printf("\nCharacters at even index positions:\n");
    
    for (i = 0; str[i] != '\0'; i += 2) {
        printf("Index %d: %c\n", i, str[i]);
    }
    
    return 0;
}
