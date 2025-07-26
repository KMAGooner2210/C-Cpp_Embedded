#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next; //Con tro tro toi nut tiep theo
} Node;

Node* create_node(int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(new_node == NULL){
		printf("Loi khong du bo nho!\n");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void print_list(Node* head){
	if(head == NULL){
		printf("Danh sach rong\n");
		return;
	}
	Node *current = head;
	while(current != NULL){
		printf("%d ", current->data);  //In gia tri cua nut hien tai
		current = current->next;  	//Chuyen den nut tiep theo
	}
	printf("\n");
}

int main(){
	Node* head = create_node(10);
	head->next = create_node(20);
	head->next->next = create_node(30);
	
	printf("Danh sach lien ket: ");
	print_list(head);
	
	Node* current = head;
	Node* temp;
	while(current != NULL){
		temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}
