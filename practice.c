#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int comparator_function(int arr[], int count, )

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int swap_marker = low - 1;
    int temp = 0;

    for (int index = low; index < high; index++) {
        if (arr[index] <= pivot) {
            swap_marker++;
            
            temp = arr[index];
            arr[index] = arr[swap_marker];
            arr[swap_marker] = temp;
        }
    }

    temp = arr[swap_marker + 1];
    arr[swap_marker + 1] = arr[high];
    arr[high] = temp;

    return swap_marker + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int num[] = {1, 4, 3, 2};
    quicksort(&num[0], 0, 3);

    for (int i = 0; i < 4; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}