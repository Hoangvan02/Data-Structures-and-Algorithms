#include <stdio.h>

void print(int arr[], int leng) {
  for (int i = 0; i < leng; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void sort(int arr[], int leng) {
  for (int step = 1; step < leng; step++) {
    int key = arr[step];
    int j = step - 1;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {6, 1, 5, 8, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  sort(arr, size);
  printf("Mảng sau khi sắp xếp là:\n");
  print(arr, size);
}
