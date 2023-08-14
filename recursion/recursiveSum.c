#include <stdio.h>
#include <time.h>

int recursiveSum(int arr[], int size);

int main(void) {
  int arr[100];
  for(int i = 0; i < 100; i++) {
    arr[i] = i + 1;
  }

  clock_t start, end;
  start = clock();
  int s = recursiveSum(arr, 100);
  end = clock();
  
  printf("The sum is %d\n", s);
  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds\n", cpu_time_used);
}

int recursiveSum(int arr[], int size) {
  if(size <= 0) {
    return 0;
  }
  return arr[size - 1] + recursiveSum(arr, size - 1);
}
