#include <stdio.h>
void sort(int arr[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}

void print(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
int main() {
  int arr[] = {4, 7, 5, 6, 0};
  int size = sizeof(arr) / sizeof(arr[0]);
  sort(arr, size);
  printf("Mảng sau khi sắp xếp có dạng như sau:\n");
  print(arr, size);
}
