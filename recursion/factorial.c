#include <stdio.h>
#include <time.h>

int factorial(int n);

int main(void) {
  clock_t start, end;
  int n = 10;

  start = clock();
  int f = factorial(n);
  end = clock();

  printf("The factorial is: %d\n", f);

  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds\n", cpu_time_used);
  return 1;
}

int factorial(int n) {
  if(n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}
