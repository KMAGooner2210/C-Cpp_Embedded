#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// T?o m?t n�t m?i
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Th�m n�t v�o cu?i danh s�ch
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

// In danh s�ch
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

// �?o ngu?c danh s�ch
void reverse_list(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;    // Luu n�t ti?p theo
        current->next = prev;    // �?o ngu?c li�n k?t
        prev = current;          // Di chuy?n prev l�n
        current = next;          // Di chuy?n current l�n
    }
    *head_ref = prev;           // C?p nh?t head
}

// Gi?i ph�ng danh s�ch
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

    // Nh?p c�c ph?n t?
    printf("Nhap %d gia tri cho danh sach:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_at_tail(&head, value);
    }

    // In danh s�ch ban d?u
    printf("Danh sach vua nhap: ");
    print_list(head);

    // �?o ngu?c danh s�ch
    reverse_list(&head);
    printf("Danh sach sau khi dao nguoc: ");
    print_list(head);

    // Gi?i ph�ng danh s�ch
    free_list(&head);
    printf("Danh sach sau khi giai phong: ");
    print_list(head);

    return 0;
}
