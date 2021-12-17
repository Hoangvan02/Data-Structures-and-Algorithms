#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
 };

typedef struct LinkedList *node; 
//tao mot node
node CreateNode(int value){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->data = value;
    return temp;
}
//Them 1 phan tu vao cuoi danh sach
node AddTail(node head, int value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;   
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

//them 1 phan tu vao dau ds
node AddHead(node head, int value){
    node temp = CreateNode(value); 
    if(head == NULL){
        head = temp; 
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}
//Them vao vi tri bat ky
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value);
    }else{
        
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }

        if(k != position){
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
//Xoa node dau
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
//Xoa node cuoi
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; 
    return head;
}
//Xoa node o vi tri bat ki
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head);
    }else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }

        if(k != position){
            head = DelTail(head);
            printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
//tim kiem trong danh sach
int Search(node head, int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
//Duyet dslk
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
//Khoi tao node head
node InitHead(){
    node head;
    head = NULL;
    return head;
}
//Nhap dslk
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu trong linked list = ");
        scanf("%d", &n);
    }while(n <= 0);

    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri bien: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}

int main(){
    printf("\nTao 1 danh sach lien ket");
    node head = Input();
    Traverser(head);

    printf("\nThem phan tu 5 cuoi linked list");
    head = AddTail(head,5);
    Traverser(head);

    printf("\nThem phan tu 7 vao dau linked list");
    head = AddHead(head,7);
    Traverser(head);

    printf("\nThem phan tu 9 vao vi tri 2 linked list");
    head = AddAt(head, 9, 2);
    Traverser(head);
                               
    printf("\nXoa 1 phan dau linked list");
    head =DelHead(head);
    Traverser(head);

    printf("\nXoa 1 phan tu bat ki khoi linked list");
    head = DelAt(head, 1);
    Traverser(head);

    printf("\nXoa 1 phan tu cuoi linked list");
    head = DelTail(head);
    Traverser(head);

    printf("\nTim kiem phan tu có giá trị là 5 trong linked list");
    int index = Search(head, 5);
    if(index == -1) printf("\nKhông có phần tử đó!");
    else printf("\nVi tri cua phan tu do la%d", index + 1);
}
     
