
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char buf[1024];
	printf("Enter a line: ");
	if (!fgets(buf, sizeof(buf), stdin)) return 0;
	size_t len = strlen(buf);
	if (len && buf[len-1]=='\n') buf[--len]=0;

	char *tokens[256];
	int n = 0;
	char *s = buf;
	char *tok = strtok(s, " \t");
	while (tok && n < (int)(sizeof(tokens)/sizeof(tokens[0]))) {
		tokens[n++] = tok;
		tok = strtok(NULL, " \t");
	}

	for (int i = n-1; i >= 0; --i) {
		printf("%s", tokens[i]);
		if (i) printf(" ");
	}
	printf("\n");
	return 0;
}
