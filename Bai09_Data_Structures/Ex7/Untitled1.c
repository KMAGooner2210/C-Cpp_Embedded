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


Node* merge_lists(Node* head1, Node* head2) {
    
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* merged_head = NULL;
    Node** tail_ref = &merged_head; 

    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            *tail_ref = head1;
            head1 = head1->next;
        } else {
            *tail_ref = head2;
            head2 = head2->next;
        }
        tail_ref = &((*tail_ref)->next);
    }

   
    if (head1 != NULL) *tail_ref = head1;
    if (head2 != NULL) *tail_ref = head2;

    return merged_head;
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
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2, value;

    // Nh?p danh sách th? nh?t
    printf("Nhap so luong phan tu cua danh sach thu nhat: ");
    scanf("%d", &n1);
    if (n1 < 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    printf("Nhap %d gia tri cho danh sach thu nhat:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insert_at_tail(&head1, value);
    }

    
    printf("Nhap so luong phan tu cua danh sach thu hai: ");
    scanf("%d", &n2);
    if (n2 < 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    printf("Nhap %d gia tri cho danh sach thu hai:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insert_at_tail(&head2, value);
    }

    
    printf("Danh sach thu nhat: ");
    print_list(head1);
    printf("Danh sach thu hai: ");
    print_list(head2);

    
    Node* merged_list = merge_lists(head1, head2);
    printf("Danh sach sau khi hop nhat: ");
    print_list(merged_list);

   
    free_list(&merged_list);
    printf("Danh sach sau khi giai phong: ");
    print_list(merged_list);

    return 0;
}
