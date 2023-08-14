#include <stdio.h>
#include <time.h>

#define ARR_SIZE 100000

int binary_search(int arr[], int target, int arr_size);

int main(void) {
  int arr[ARR_SIZE];
  for(int i = 0; i < ARR_SIZE; i++) {
    arr[i] = i + 1;
  }

  clock_t start, end;

  start = clock();
  int found_index = binary_search(arr, 100000, ARR_SIZE);
  end = clock();
  printf("Index is: %i\n", found_index);
  
  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds\n", cpu_time_used);
  return 0;
}

int binary_search(int arr[], int target, int arr_size) {
  int high = arr_size - 1;
  int low = 0;
  int mid;

  while(low <= high) {
    mid = (low + high) / 2;
    if(arr[mid] == target) {
      return mid;
    }
    else if(arr[mid] < target) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}
