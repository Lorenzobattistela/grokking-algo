#include <stdio.h>
#include <time.h>

int count_items(int arr[], int size);

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int items_count = count_items(arr, 5);
    printf("This array has %d items.\n", items_count);
  }

  int count_items(int arr[], int size) {
    if(size <= 0) {
      return 0;
    }
    return 1 + count_items(arr, size - 1);
}
