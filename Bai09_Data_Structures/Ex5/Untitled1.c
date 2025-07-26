#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// T?o m?t nút m?i
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Thêm nút vào cu?i danh sách
void insert_at_tail(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// In danh sách
void print_list(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Ð?o ngu?c danh sách
void reverse_list(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;    // Luu nút ti?p theo
        current->next = prev;    // Ð?o ngu?c liên k?t
        prev = current;          // Di chuy?n prev lên
        current = next;          // Di chuy?n current lên
    }
    *head_ref = prev;           // C?p nh?t head
}

// Gi?i phóng danh sách
void free_list(Node** head_ref) {
    Node* current = *head_ref;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head_ref = NULL;
}

int main() {
    Node* head = NULL;
    int n, value;

    // Nh?p s? lu?ng ph?n t?
    printf("Nhap so luong phan tu cua danh sach: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nh?p các ph?n t?
    printf("Nhap %d gia tri cho danh sach:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_at_tail(&head, value);
    }

    // In danh sách ban d?u
    printf("Danh sach vua nhap: ");
    print_list(head);

    // Ð?o ngu?c danh sách
    reverse_list(&head);
    printf("Danh sach sau khi dao nguoc: ");
    print_list(head);

    // Gi?i phóng danh sách
    free_list(&head);
    printf("Danh sach sau khi giai phong: ");
    print_list(head);

    return 0;
}
