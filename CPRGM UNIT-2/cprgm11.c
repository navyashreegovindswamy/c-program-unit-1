#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int binary_search(int arr[], int l, int r, int x) {
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int find_closest(int arr[], int n, int x) {
	int closest = arr[0];
	int minDiff = abs(arr[0] - x);
	for (int i = 1; i < n; i++) {
		int d = abs(arr[i] - x);
		if (d < minDiff) {
			minDiff = d;
			closest = arr[i];
		} else if (d == minDiff && arr[i] > closest) {
			/* If equal distance prefer the larger value */
			closest = arr[i];
		}
	}
	return closest;
}

int main(void) {
	int n;
	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n <= 0) return 0;

	int *arr = malloc(n * sizeof(int));
	if (!arr) return 1;

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) { free(arr); return 0; }
	}

	int target;
	printf("Enter target to search: ");
	if (scanf("%d", &target) != 1) { free(arr); return 0; }

	bubble_sort(arr, n);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");

	int idx = binary_search(arr, 0, n - 1, target);
	if (idx != -1) {
		printf("%d found at sorted index %d\n", target, idx);
	} else {
		int smallest = find_smallest(arr, n, target);
		int largest = arr[n - 1];
		printf("%d not found.\nsmallest value: %d\nLargest value: %d\n", target, smallest, largest);
	}

	free(arr);
	return 0;
}

