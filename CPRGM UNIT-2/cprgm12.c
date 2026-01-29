#include <stdio.h>
#include <stdlib.h>

void bubble_sort_asc(int arr[], int n) {
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

void bubble_sort_desc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
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

int *search_using_pointer(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == x) {
            return (arr + i);
        }
    }
    return NULL;
}

void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int n;
    printf("\n=== BUBBLE SORT & BINARY SEARCH WITH POINTER SEARCH ===\n");
    printf("Enter number of elements: ");
    fflush(stdout);
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        fflush(stdout);
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 0;
        }
    }

    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Bubble Sort (Smallest to Largest)\n");
        printf("2. Bubble Sort (Largest to Smallest)\n");
        printf("3. Binary Search\n");
        printf("4. Search using Pointer\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        fflush(stdout);
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            bubble_sort_asc(arr, n);
            printf("Array sorted (Smallest to Largest): ");
            print_array(arr, n);
        }
        else if (choice == 2) {
            bubble_sort_desc(arr, n);
            printf("Array sorted (Largest to Smallest): ");
            print_array(arr, n);
        }
        else if (choice == 3) {
            int target;
            printf("Enter target to search: ");
            fflush(stdout);
            if (scanf("%d", &target) != 1) {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                continue;
            }
            int idx = binary_search(arr, 0, n - 1, target);
            if (idx != -1) {
                printf("%d found at index %d\n", target, idx);
            } else {
                printf("%d not found.\n", target);
            }
        }
        else if (choice == 4) {
            int target;
            printf("Enter target to search: ");
            fflush(stdout);
            if (scanf("%d", &target) != 1) {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                continue;
            }
            int *ptr = search_using_pointer(arr, n, target);
            if (ptr != NULL) {
                printf("%d found at address %p, value = %d\n", target, (void *)ptr, *ptr);
            } else {
                printf("%d not found.\n", target);
            }
        }
        else if (choice == 5) {
            print_array(arr, n);
        }
        else if (choice == 6) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(arr);
    return 0;
}
