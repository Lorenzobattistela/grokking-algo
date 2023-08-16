#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printMatrix(int matrix[4][4]) {
    printf("Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d ", matrix[i][j]); // Adjust the width as needed
        }
        printf("\n");
    }
}

int main(void) {
  char *typed = "abcd";
  char *a = "abce";
  char *b = "vist";
  int wordLength = 4;
  int matrix[wordLength][wordLength];

  for(int i = 0; i < wordLength; i++) {
    for(int j = 0; j < wordLength; j++) {
      if(a[i] == typed[j]) {
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      }
      else {
        matrix[i][j] = 0;
      }
    }
  }

  // printMatrix(matrix);
  
  int maxLength = 0;
  int maxI = 0;
  int maxJ = 0;

  for(int i = 0; i < wordLength; i++) {
    for(int j = 0; j < wordLength; j++) {
      if(matrix[i][j] > maxLength) {
        maxLength = matrix[i][j];
        maxI = i;
        maxJ = j;
      }
    }
  }

  char longestSubstring[maxLength + 1];
  strncpy(longestSubstring, typed + maxJ - maxLength + 1, maxLength);
  longestSubstring[maxLength] = '\0';
  printf("Longest common substring: %s\n", longestSubstring);
}
