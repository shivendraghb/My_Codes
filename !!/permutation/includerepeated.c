// C Program: Unique Permutations Using Next Permutation Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool nextPermutation(int arr[], int size) {
    int i = size - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }

    int j = size - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    swap(&arr[i], &arr[j]);

    for (int start = i + 1, end = size - 1; start < end; start++, end--) {
        swap(&arr[start], &arr[end]);
    }
    return true;
}

void printPermutations(int arr[], int size) {
    do {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } while (nextPermutation(arr, size));
}

int main() {
    int arr[] = {1,1,2}; // Array with duplicates and unsorted values
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array to ensure nextPermutation works correctly
    qsort(arr, size, sizeof(int), compare);

    printf("Unique permutations using Next Permutation algorithm:\n");
    printPermutations(arr, size);

    return 0;
}

// Explanation:
// - Uses the next permutation algorithm instead of backtracking.
// - Sorts the array before generating permutations.
// - Automatically skips duplicates due to lexicographical ordering.
// - Outputs all unique permutations including negative numbers and zero.
