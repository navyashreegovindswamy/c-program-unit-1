#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[1024], s2[1024];

    if (argc >= 3) {
        strncpy(s1, argv[1], sizeof(s1)-1); s1[sizeof(s1)-1] = '\0';
        strncpy(s2, argv[2], sizeof(s2)-1); s2[sizeof(s2)-1] = '\0';
    } else {
        printf("Enter first string: ");
        if (!fgets(s1, sizeof(s1), stdin)) return 0;
        if (s1[strlen(s1)-1] == '\n') s1[strlen(s1)-1] = '\0';

        printf("Enter second string: ");
        if (!fgets(s2, sizeof(s2), stdin)) return 0;
        if (s2[strlen(s2)-1] == '\n') s2[strlen(s2)-1] = '\0';
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        printf("\"%s\" is NOT a rotation of \"%s\"\n", s2, s1);
        return 0;
    }

    char concat[2048];
    concat[0] = '\0';
    strncat(concat, s1, sizeof(concat)-1);
    strncat(concat, s1, sizeof(concat)-strlen(concat)-1);

    if (strstr(concat, s2) != NULL) {
        printf("\"%s\" is a rotation of \"%s\"\n", s2, s1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\"\n", s2, s1);
    }

    return 0;
}
