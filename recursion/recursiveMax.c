#include <stdio.h>

int recursive_max(int arr[], int size);

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  int max_n = recursive_max(arr, 5);
  printf("The max num in this array is %d\n", max_n);
}

int max = 0;
int recursive_max(int arr[], int size) {
  if(size == 0) {
    return max;
  }
  if(arr[size - 1] > max) max = arr[size - 1];

  return recursive_max(arr, size - 1);
}
