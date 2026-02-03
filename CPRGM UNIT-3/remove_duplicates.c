#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char result[100];
    int i, j, k = 0;
    int found;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        found = 0;

        for (j = 0; j < k; j++) {
            if (str[i] == result[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
    
    printf("String after removing duplicates: %s\n", result);
    
    return 0;
}
