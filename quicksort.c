#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int divide(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void sort(int arr[], int low, int high) {
  if (low < high) {
    int pi = divide(arr, low, high);
    sort(arr, low, pi - 1);
    sort(arr, pi + 1, high);
  }
}

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 9, 4, 3, 2, 11, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, 0, n - 1);
  printf("Mảng sau khi sắp xếp có dạng là: \n");
  print(arr, n);
}
