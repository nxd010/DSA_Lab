#include <stdio.h>

#define MAX_SIZE 10

void displayArray(int arr[], int size) {
    printf("array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE || position < 0 || position > *size) {
        printf("Unable to Insert Element at Position %d.\n", position);
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
}

void deleteLastElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete any element.\n");
        return;
    }

    (*size)--;
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    printf("Original ");
    displayArray(arr, size);

    insertElement(arr, &size, 99, 3);  // Insert 99 at position 3
    insertElement(arr, &size, 77, 8);  // Insert 77 at position 8

    printf("After Insertion ");
    displayArray(arr, size);

    deleteLastElement(arr, &size);

    printf("After Deletion ");
    displayArray(arr, size);

    return 0;
}
