#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Find length of string
int string_length(const char *str) {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Find largest and smallest words in a sentence
void find_largest_smallest_word(const char *sentence) {
    if (!sentence) return;

    int n = string_length(sentence);
    char largest[256] = {0};
    char smallest[256] = {0};
    int max_len = 0;
    int min_len = 256;

    int i = 0;
    while (i < n) {
        // Skip non-alphabetic characters
        while (i < n && !isalpha((unsigned char)sentence[i])) {
            i++;
        }

        if (i >= n) break;

        // Extract word
        char word[256] = {0};
        int j = 0;
        while (i < n && isalpha((unsigned char)sentence[i])) {
            word[j++] = sentence[i];
            i++;
        }
        word[j] = '\0';

        int word_len = j;

        // Update largest word
        if (word_len > max_len) {
            max_len = word_len;
            strcpy(largest, word);
        }

        // Update smallest word
        if (word_len < min_len) {
            min_len = word_len;
            strcpy(smallest, word);
        }
    }

    printf("Sentence: \"%s\"\n\n", sentence);
    if (max_len > 0) {
        printf("Largest word: \"%s\" (length: %d)\n", largest, max_len);
    }
    if (min_len < 256) {
        printf("Smallest word: \"%s\" (length: %d)\n", smallest, min_len);
    }
}

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) {
        // Concatenate all arguments as a single sentence
        static char buf[2048];
        buf[0] = '\0';
        for (int i = 1; i < argc; ++i) {
            if (i > 1) strcat(buf, " ");
            strcat(buf, argv[i]);
        }
        input = buf;
    } else {
        // Read from stdin
        static char buf[2048];
        printf("Enter a sentence: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    find_largest_smallest_word(input);
    return 0;
}
