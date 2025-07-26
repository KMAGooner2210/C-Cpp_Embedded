#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
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
	Node* current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void delete_node(Node** head_ref, int data){
	Node* current = *head_ref;
	Node* prev = NULL;
	
	if(current == NULL){
		return;
	}
	
	// Truong hop nut dau tien chua data
	if(current->data == data){
		*head_ref = current->next;
		free(current);
		return;
	}
	
	// Tim nut chua data
	while(current != NULL && current->data != data){
		prev = current;
		current = current->next;
	}
	
	// Neu khong tim thay data
	if(current == NULL){
		return;
	}
	
	// Xoa nut chua data
	prev->next = current->next;
	free(current);
}

//Ham tim nut dau tien chua gia data
Node* search_node(Node* head, int data){
	Node* current = head;
	while(current != NULL){
		if(current->data == data){
			return current;
		}
		current = current->next;
	}
	return NULL;
}

int main(){
	Node* head = NULL;
	
	insert_at_head(&head, 40);
	insert_at_head(&head, 30);
	insert_at_head(&head, 20);
	insert_at_head(&head, 10);
	
	printf("Danh sach ban dau: ");
	print_list(head);
	
	//Tim so 30
	Node* found = search_node(head, 30);
	if(found != NULL){
		printf("Tim thay %d trong danh sach\n", found->data);
	}else{
		printf("Khong tim thay 30 trong danh sach\n");
	}
	
	//Xoa so 20
	delete_node(&head, 20);
	printf("Danh sach sau khi xoa 20: ");
	print_list(head);
	
	Node* current = head;
	while(current != NULL){
		Node* temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}
