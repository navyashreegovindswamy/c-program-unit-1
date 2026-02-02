/* Find longest substring with at least one digit and no repeating characters */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char s[1024];
	if (!fgets(s, sizeof s, stdin)) return 0;
	size_t n = strcspn(s, "\n");
	s[n] = '\0';

	int freq[256] = {0};
	size_t start = 0;
	size_t best_start = 0, best_len = 0;
	int digit_count = 0;

	for (size_t i = 0; i < n; ++i) {
		unsigned char c = (unsigned char)s[i];

		// Shrink window while current char would be a duplicate
		while (freq[c] > 0) {
			unsigned char rem = (unsigned char)s[start++];
			if (isdigit(rem)) --digit_count;
			--freq[rem];
		}

		// Add current char
		++freq[c];
		if (isdigit(c)) ++digit_count;

		// If window has at least one digit, consider update
		size_t cur_len = i - start + 1;
		if (digit_count > 0 && cur_len > best_len) {
			best_len = cur_len;
			best_start = start;
		}
	}

	if (best_len == 0) {
		printf("No substring found that contains a digit with all unique characters.\n");
		return 0;
	}

	// Print characters separated by spaces as requested
	for (size_t i = 0; i < best_len; ++i) {
		if (i) printf(" ");
		printf("%c", s[best_start + i]);
	}
	printf("\n");
	return 0;
}

