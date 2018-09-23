#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

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

struct list *deleteNode(struct list *head, int position) {
	struct list *temp;
	int pos = 0;
	temp = head;
	if (position == 0) {
		head = temp->next;
		temp->next = NULL;
		free(temp);
		return head;
	}
	while (temp != NULL) {
		if (pos == position-1) {
			struct list *ptr = temp->next;
			temp->next = ptr->next;
			ptr->next = NULL;
			free(ptr);
		}
		temp = temp->next;
		pos++;
	}
	return head;
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
	int position;
	printf("Enter position of node to be deleted :");
	scanf("%d",&position);
	head = deleteNode(head,position);
	printf("List after deleting node node at %d ....\n", position);
	printList(head);
	printf("\n");
}	
