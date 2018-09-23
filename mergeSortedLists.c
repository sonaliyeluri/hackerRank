#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *createList(int n) {
	struct list *head, *temp1, *temp2;
	head = malloc(sizeof(struct list));
	temp1 = head;
	int i;
	printf("Enter Elements to list ...");
	scanf("%d",&temp1->data);
	temp1->next = NULL;
	for (i=0;i<n-1;i++) {
		temp2 = malloc(sizeof(struct list));
		scanf("%d",&temp2->data);
		temp2->next = NULL;
		temp1->next = temp2;
		temp1 = temp2;
	}
	return head;
}

void printList(struct list *head) {
	while (head != NULL) {
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

struct list *mergeSortedLists(struct list *head1, struct list *head2) {
	if (head1 == NULL && head2 != NULL)
		return head2;
	if (head1 != NULL && head2 == NULL)
		return head1;
	if (head1->data < head2->data) {
		head1->next = mergeSortedLists(head1->next, head2);
		return head1;
	}
	else {
		head2->next = mergeSortedLists(head1, head2->next);
		return head2;
	}
}

int main() {
	struct list *head1, *head2;
	int n1, n2;
	printf("Enter size of first list: ");
	scanf("%d",&n1);
	head1 = createList(n1);
	printf("Elements of First list..\n");
	printList(head1);
	printf("Enter size of second list: ");
        scanf("%d",&n2);
	head2 = createList(n2);
	printf("Elements of Second list..\n");
        printList(head2);
	printf("Elements of list after merging two lists ..\n");
	struct list *head3 = mergeSortedLists(head1, head2);
	printList(head3);
}
