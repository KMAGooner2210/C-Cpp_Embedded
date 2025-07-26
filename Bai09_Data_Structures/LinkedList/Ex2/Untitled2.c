#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* create_node(int data){
	Node* new_node =(Node*) malloc(sizeof(Node));
	if(new_node == NULL){
		printf("Loi: Khong du bo nho!\n");
		exit(1);
	}
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

void print_list(Node* head){
	if(head == NULL){
		printf("Danh sach rong!\n");
		return;
	}
	Node* current = head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void insert_at_head(Node** head_ref, int data){
	Node* new_node = create_node(data); 	//Tao nut moi
	new_node->next = *head_ref;				//Lien ket nut moi voi danh sach hien tai
	*head_ref = new_node;					//Cap nhat head de tro toi nut moi	
}

void insert_at_end(Node** head_ref, int data){
	Node* new_node = create_node(data);
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	Node* current = *head_ref;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new_node;
}

int main(){
	Node *head = NULL;
	
	printf("Them 5 vao dau: ");
	insert_at_head(&head, 5);
	print_list(head);
	
	printf("Them 15 vao dau: ");
	insert_at_head(&head, 25);
	print_list(head);
	
	printf("Them 24 vao cuoi: ");
	insert_at_end(&head, 24);
	print_list(head);
	
	Node *current = head;
	Node *temp;
	while(current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}


