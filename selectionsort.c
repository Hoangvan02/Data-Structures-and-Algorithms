#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int arr[], int leng) {
  for (int step = 0; step < leng - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < leng; i++) {
      if (arr[i] < arr[min_idx])
        min_idx = i;
    }
    swap(&arr[min_idx], &arr[step]);
  }
}

void print(int arr[], int leng) {
  for (int i = 0; i < leng; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {9, 6, 5, 8, 4, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  sort(arr, size);
  printf("Mảng sau khi được sắp xếp:\n");
  print(arr, size);
}
