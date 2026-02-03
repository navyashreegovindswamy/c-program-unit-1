#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    char words[50][50];
    int wordCount = 0;
    int i = 0, j = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            j = 0;
    
            while (str[i] != '\0' && isalpha(str[i])) {
                words[wordCount][j++] = str[i];
                i++;
            }
            words[wordCount][j] = '\0';
            wordCount++;
        }
    }
    
    if (wordCount == 0) {
        printf("No words found in the string.\n");
        return 0;
    }
    
    char smallest[50], largest[50];
    strcpy(smallest, words[0]);
    strcpy(largest, words[0]);
    
    for (i = 1; i < wordCount; i++) {
        if (strlen(words[i]) < strlen(smallest)) {
            strcpy(smallest, words[i]);
        }
        if (strlen(words[i]) > strlen(largest)) {
            strcpy(largest, words[i]);
        }
    }
    
    printf("\nSmallest word: %s (length: %zu)\n", smallest, strlen(smallest));
    printf("Largest word: %s (length: %zu)\n", largest, strlen(largest));
    
    return 0;
}
