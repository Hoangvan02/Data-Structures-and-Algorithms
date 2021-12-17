#include <stdio.h>
void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
  
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

void sort_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}
  
void print(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 14, 11, 7, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_heap(arr, n);
    printf("Mảng sau khi sắp xếp là: \n");
    print(arr, n);
}
