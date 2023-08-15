#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void swap(int *a, int *b);

int main(void) {
  int n = 10;
  int arr[10] = { 1, 3, 9, 2, 5, 3, 6, 7, 4, 10};

  quicksort(arr, 0, n-1);
  printf("Sorted array:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void quicksort(int arr[], int low, int high) {
  if(low < high) {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j <= high - 1; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
