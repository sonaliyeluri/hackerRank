#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *newNode(int data) {
	struct list *node = malloc(sizeof(struct list));
	node->data = data;
	node->next = NULL;
	return node;
}

struct list *createList(int n) {
	int i;
	struct list *root;
	struct list *temp1, *temp2;
	root = malloc(sizeof(struct list));
	temp1 = root;
	printf("Enter Elements to List..");
	scanf("%d",&temp1->data);
	temp1->next = NULL;
	for (i=0;i<n-1;i++) {
		temp2 = malloc(sizeof(struct list));
		scanf("%d",&temp2->data);
		temp2->next = NULL;
		temp1->next = temp2;
		temp1= temp2;
	}
	return root;
}

void printList(struct list *root) {
	while (root != NULL) {
		printf("%d ",root->data);
		root = root->next;
	}
	printf("\n");
}

struct list *insertNodeatTail(struct list *root, int data) {
	struct list *temp, *last;
	temp = root;
	last = newNode(data);
	printf("Adding node at Tail of list..\n");
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = last;
	return root;
}
				
int main() {
	int n;
	printf("Enter size of Linked list: ");
	scanf("%d",&n);
	struct list *head;
	head = createList(n);
	printf("Elements of list ...\n");
	printList(head);
	printf("\n");
	head = insertNodeatTail(head, 10);
	printf("List after adding node at last ....\n");
	printList(head);
	printf("\n");
}	
