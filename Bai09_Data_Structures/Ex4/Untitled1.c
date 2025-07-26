#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* create_node(int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert_at_head(Node** head_ref, int data){
	Node* new_node = create_node(data);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print_list(Node* head){
	if(head == NULL){
		printf("Danh sach rong\n");
		return;
	}
	Node* current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void free_list(Node** head_ref){
	Node* current = *head_ref;
	while(current != NULL){
		Node* temp = current;
		current = current->next;
		free(temp);
	}
	*head_ref = NULL;
}

int main(){
	Node* head = NULL;
	
	insert_at_head(&head, 15);
	insert_at_head(&head, 10);
	insert_at_head(&head, 5);
	
	printf("Danh sach ban dau: ");
	print_list(head);
	
	free_list(&head);
	printf("Danh sach sau khi giai phong: ");
	print_list(head);
	
	return 0;
}

