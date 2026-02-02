/* Demonstration of dynamic memory allocation and deallocation */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;

	/* malloc: allocate an array of 5 ints */
	size_t n = 5;
	int *arr = malloc(n * sizeof *arr);
	if (!arr) {
		perror("malloc");
		return 1;
	}
	for (i = 0; i < (int)n; ++i) arr[i] = i + 1;
	printf("Initial array (%zu):", n);
	for (i = 0; i < (int)n; ++i) printf(" %d", arr[i]);
	printf("\n");

	/* realloc: grow the array to 8 elements */
	size_t newn = 8;
	int *tmp = realloc(arr, newn * sizeof *arr);
	if (!tmp) {
		perror("realloc");
		free(arr);
		return 1;
	}
	arr = tmp;
	for (i = (int)n; i < (int)newn; ++i) arr[i] = i + 1;
	printf("After realloc (%zu):", newn);
	for (i = 0; i < (int)newn; ++i) printf(" %d", arr[i]);
	printf("\n");

	/* free the array and null the pointer */
	free(arr);
	arr = NULL;

	/* calloc: allocate and zero-initialize 3 ints */
	size_t m = 3;
	int *b = calloc(m, sizeof *b);
	if (!b) {
		perror("calloc");
		return 1;
	}
	printf("Calloc array (%zu):", m);
	for (i = 0; i < (int)m; ++i) printf(" %d", b[i]);
	printf("\n");

	free(b);
	b = NULL;

	printf("Memory freed; pointers set to NULL.\n");
	return 0;
}

