
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
    int count = 0;
    while (current != NULL && count < 15) { // Gi?i h?n in d? tránh vòng vô h?n
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
        count++;
    }
    printf("\n");
}

int has_cycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
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
    int n, value, create_cycle, cycle_pos;

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

    printf("Danh sach vua nhap: ");
    print_list(head);

    // Ki?m tra vòng ban d?u
    printf("Co vong? %d (0: Khong, 1: Co)\n", has_cycle(head));

    // H?i ngu?i dùng có mu?n t?o vòng không
    printf("Ban co muon tao vong trong danh sach? (1: Co, 0: Khong): ");
    scanf("%d", &create_cycle);

    if (create_cycle == 1) {
        // Nh?p v? trí nút d? t?o vòng (1-based index)
        printf("Nhap vi tri (1 den %d) de tao vong (nuoc tro ve nut nay): ", n);
        scanf("%d", &cycle_pos);
        if (cycle_pos < 1 || cycle_pos > n) {
            printf("Vi tri khong hop le!\n");
        } else {
            // Tìm nút cu?i và nút t?i v? trí cycle_pos
            Node* last = head;
            Node* cycle_node = head;
            int pos = 1;
            while (last->next != NULL) {
                last = last->next;
            }
            while (pos < cycle_pos && cycle_node != NULL) {
                cycle_node = cycle_node->next;
                pos++;
            }
            if (cycle_node != NULL) {
                last->next = cycle_node; // T?o vòng
                printf("Danh sach sau khi tao vong: ");
                print_list(head);
                printf("Co vong? %d (0: Khong, 1: Co)\n", has_cycle(head));
                // Phá vòng tru?c khi gi?i phóng
                last->next = NULL;
            } else {
                printf("Khong the tao vong do vi tri khong ton tai!\n");
            }
        }
    }

    // Gi?i phóng danh sách
    free_list(&head);
    printf("Danh sach sau khi giai phong: ");
    print_list(head);

    return 0;
}

