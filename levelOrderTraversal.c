#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode (int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

int height (struct tree *root) {
	if (root == NULL)
		return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (leftHeight > rightHeight)
		return leftHeight+1;
	else
		return rightHeight+1;
}

void printGivenLevel (struct tree *root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ",root->data);
	else {
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

void levelOrder(struct tree *root) {
	int i;
	int h = height(root);
	for (i=1;i<=h;i++)
		printGivenLevel(root, i);
}

int main() {
	struct tree *root;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("Level Order Traversal of tree ...\n");
	levelOrder(root);
	printf("\n");
	return 0;
}
