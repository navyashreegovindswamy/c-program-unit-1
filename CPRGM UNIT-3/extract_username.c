#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    const char *input = NULL;
    if (argc > 1) input = argv[1];
    else {
        static char buf[1024];
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        buf[strcspn(buf, "\r\n")] = '\0';
        input = buf;
    }

    const char *at = strchr(input, '@');
    if (!at) {
        printf("Invalid email\n");
        return 0;
    }

    if (at == input) {
        printf("\n");
        return 0;
    }

    size_t len = (size_t)(at - input);
    char *user = malloc(len + 1);
    if (!user) return 0;
    memcpy(user, input, len);
    user[len] = '\0';
    printf("%s\n", user);
    free(user);
    return 0;
}
