#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addHead(Node** head, Node** tail, int data){
    Node*  newNode = createNode(data);
    if(*head == NULL){
        *head = *tail = newNode;
    }else{
        newNode->next = *head;
        (*head) -> prev = newNode;
        *head = newNode;
}
}
void addFoot(Node** head, Node** tail, int data){
    Node* newNode = createNode(data);
    if(*tail == NULL){
        *head = *tail = newNode;
    }else{
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void deleteHead(Node** head, Node** tail){
    if(*head == NULL){
        printf("Danh sách rỗng ");
        return;
    }
    Node *temp = *head;
    if(*head == *tail){
        *head = *tail = NULL;
    }else{
        *head = (*head)-> next;
        (*head) -> prev = NULL;
    }
    free(temp);
    printf("Xoa phan tu dau danh sach thanh cong");
}
void deleteFoot(Node** head, Node** tail){
    if(*tail == NULL){
        printf("Danh sach rong ");
        return;
    }
    Node* temp = *tail;
    if(*head == *tail){
        *head = *tail = NULL;
    }else{
        *tail = (*tail) -> prev;
        (*tail) -> next = NULL;
    }
    free(temp);
    printf("Xoa phan tu cuoi danh sach thanh cong");
}

void deleteByValue(Node** head, Node** tail, int data) {
    if (*head == NULL) {
        printf("Danh sách rỗng\n");
        return;
    }
    Node* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Giá trị không tồn tại trong danh sách\n");
        return;
    }
    if (temp == *head) {
        deleteHead(head, tail);
        return;
    }
    if (temp == *tail) {
        deleteFoot(head, tail);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Xóa giá trị %d thành công\n", data);
}


void printHeadToFoot(Node* head){
    Node* temp = head;
    printf("Danh sách từ đầu đến cuối của liên kết đôi: \n");
    printf("NULL <-> ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printFootToHead(Node* tail){
    Node* temp = tail;
    printf("Danh sách từ cuối đến đầu của liên kết đôi: \n");
    printf("NULL <-> ");
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    int choice;
    do{
        printf("\n================================MENU================================");
        printf("\n1. Thêm phần tử vào đầu danh sách");
        printf("\n2. Thêm phần tử vào cuối danh sách");
        printf("\n3. Chèn phần tử vào vị trí cụ thể ");
        printf("\n4. Xóa phần tử đầu danh sách");
        printf("\n5. Xóa phần tử cuối danh sách");
        printf("\n6. Xóa phần tử theo giá trị");
        printf("\n7. Duyệt danh sách từ đầu đến cuối");
        printf("\n8. Duyệt danh sách từ cuối đến đầu");
        printf("\n9. Thoát");
        
        printf("\nNhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &data);
            addHead(&head, &tail,data);
            break;

            case 2: 
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &data);
            addFoot(&head, &tail,data);
            break;

            case 3: 
            printf("Chua lam.....");
            break;

            case 4: 
            deleteHead(&head, &tail);
            break;
            
            case 5: 
            deleteFoot(&head, &tail);
            break;

            case 6:
            printf("Nhập giá trị cần xoá: ");
            scanf("%d", &data);
            deleteByValue(&head,&tail, data);
            break;

            case 7:
            printHeadToFoot(head);
            break;

            case 8:
            printFootToHead(tail);
            break;

            case 9:
            exit(0);

            default:
            printf("Vui lòng nhập lại: ");
        }
    }while(1==1);

    return 0;
}