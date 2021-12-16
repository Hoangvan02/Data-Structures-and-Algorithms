#include <stdio.h>
#define MAX 5
int data[MAX], front = -1, rear = -1;

void enQueue(int new_data) {
  if (rear == MAX - 1)
    printf("\nHàng đợi đã đầy\n");
  else {
    if (front == -1)
      front = 0;
    rear++;
    data[rear] = new_data;
    printf("\nPhần tử đã thêm %d", new_data);
    printf("\n");
  }
}

void deQueue() {
  if (front == -1)
    printf("\nHàng đợi rỗng\n");
  else {
    printf("\nPhần tử được lấy ra %d\n", data[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void in() {
  printf("\n");
  if (rear == -1)
    printf("Hàng đợi rỗng\n");
  else {
    printf("Các phần tử là: ");
    for (int i = front; i <= rear; i++)
      printf("%d ", data[i]);
  }
  printf("\n");
}

int main() {
  deQueue();
  enQueue(32);
  enQueue(42);
  enQueue(33);
  enQueue(28);
  enQueue(36);
  enQueue(50);
  in();
  deQueue();
  in();
  return 0;
}
