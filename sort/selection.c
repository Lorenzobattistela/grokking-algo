#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

#define ARR_SIZE 10

int* sort(int arr[]);
int find_min_index(int arr[]);

int main(void) {
  srand(time(NULL));
  int arr[ARR_SIZE];
  clock_t start, end;

  for(int i = 0; i < ARR_SIZE; i++) {
    arr[i] = rand() % INT_MAX;
  }

  start = clock();
  int *sorted_arr = sort(arr);
  end = clock();
 
  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Cpu time used: %f", cpu_time_used);

  free(sorted_arr);
  return 0;
}

int* sort(int arr[]) {
  int *new_arr = (int *)malloc(ARR_SIZE * sizeof(int));
  if(new_arr == NULL) {
    printf("Memory Allocation failed.\n");
    exit(1);
  }

  int min_index;
  for(int i = 0; i < ARR_SIZE; i++) {
    min_index = find_min_index(arr);
    new_arr[i] = arr[min_index];
    arr[min_index] = INT_MAX;
  }
  return new_arr;
}

int find_min_index(int arr[]) {
  int index = -1;
  int min_element = INT_MAX; 
  for(int i = 0; i < ARR_SIZE; i++) {
    if(arr[i] < min_element) {
      min_element = arr[i];
      index = i;
    }
  }
  return index;
}
