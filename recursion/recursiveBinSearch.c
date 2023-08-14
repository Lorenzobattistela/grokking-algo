#include <stdio.h>
#include <time.h>

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return recursiveBinarySearch(arr, mid + 1, right, target);
        } else {
            return recursiveBinarySearch(arr, left, mid - 1, target);
        }
    }

    return -1;
}

int main() {
    int n = 100000; // Specify the size of the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int target = arr[n - 1]; // Set target to the last element of the array

    clock_t start, end;

    start = clock();
    int indx = recursiveBinarySearch(arr, 0, n - 1, target);
    end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    if (indx != -1) {
        printf("Target element found at index %d.\n", indx);
    } else {
        printf("Target element not found in the array.\n");
    }

    return 0;
}

