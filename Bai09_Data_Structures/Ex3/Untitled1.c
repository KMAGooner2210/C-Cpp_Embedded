
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


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


Node* search_node(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void delete_node(Node** head_ref, int data) {
    if (*head_ref == NULL) {
        return;
    }
    Node* current = *head_ref;
    Node* prev = NULL;
    
    if (current->data == data) {
        *head_ref = current->next;
        free(current);
        return;
    }
    
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return;
    }
    
    prev->next = current->next;
    free(current);
}


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
    int n, value, search_value, delete_value;

    
    printf("Nhap so luong phan tu cua danh sach: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    
    printf("Nhap %d gia tri cho danh sach:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_at_tail(&head, value);
    }

    
    printf("Danh sach vua nhap: ");
    print_list(head);

    
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &search_value);
    Node* found_node = search_node(head, search_value);
    if (found_node != NULL) {
        printf("Tim kiem gia tri %d: Tim thay tai dia chi %p\n", search_value, found_node);
    } else {
        printf("Tim kiem gia tri %d: Khong tim thay\n", search_value);
    }

    
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &delete_value);
    delete_node(&head, delete_value);
    printf("Danh sach sau khi xoa %d: ", delete_value);
    print_list(head);

    
    free_list(&head);
    printf("Danh sach sau khi giai phong: ");
    print_list(head);

    return 0;
}

