/* Count digits, letters, spaces and special characters in a string
   Assumption: "arrays" in the request means alphabetic letters.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	char buf[1024];
	printf("Enter a string: ");
	if (!fgets(buf, sizeof buf, stdin)) return 0;
	size_t len = strcspn(buf, "\n");
	buf[len] = '\0';

	int digits = 0, letters = 0, spaces = 0, specials = 0;
	for (size_t i = 0; i < len; ++i) {
		unsigned char c = (unsigned char)buf[i];
		if (isdigit(c)) ++digits;
		else if (isalpha(c)) ++letters;
		else if (isspace(c)) ++spaces;
		else ++specials;
	}

	printf("Digits: %d\n", digits);
	printf("Letters: %d\n", letters);
	printf("Spaces: %d\n", spaces);
	printf("Special characters: %d\n", specials);
	return 0;
}

