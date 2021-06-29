//An internal node is a node which carries at least one child or in other words,
//an internal node is not a leaf node.
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node* createNode(int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void addToTree(char ch, struct Node *root_ref, struct Node *new_node)
{
	if (ch == 'L')
		root_ref->left = new_node;
	else if (ch == 'R')
		root_ref->right = new_node;
}

int fun(struct Node *root_ref)
{
	if (root_ref == NULL)
		return 0;
	if (root_ref->left == NULL && root_ref->right == NULL)
		return 0;
	return 1 + fun(root_ref->left) + fun(root_ref->right);
}

void main()
{
	struct Node *root1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9;
	root1 = createNode(1);
	node2 = createNode(2);
	node3 = createNode(3);
	node4 = createNode(4);
	node5 = createNode(5);
	node6 = createNode(6);
	node7 = createNode(7);
	node8 = createNode(8);
	node9 = createNode(9);
	addToTree('L', root1, node2);
	addToTree('R', root1, node3);
	addToTree('L', node2, node4);
	addToTree('R', node2, node5);
	addToTree('L', node3, node6);
	addToTree('R', node3, node7);
	addToTree('L', node5, node8);
	addToTree('R', node5, node9); 
	printf("Number of internal nodes : %d ", fun(root1));
	_getch();
}