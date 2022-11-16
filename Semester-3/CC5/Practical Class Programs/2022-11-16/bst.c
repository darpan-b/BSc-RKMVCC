#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node
{
	int data;
	struct bst_node* lchild;
	struct bst_node* rchild;
} node;

node* root = NULL;
 
node* createnode(int data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->data = data;
	return newnode;
}

void insert_node(int data)
{
	if(root == NULL)
	{
		root = createnode(data);
		return;
	}
	node* curnode = root;
	while(1)
	{
		if(data < curnode->data)
		{
			if(curnode->lchild == NULL) break;
			else curnode = curnode->lchild;
		}
		else if(data > curnode->data)
		{
			if(curnode->rchild == NULL) break;
			else curnode = curnode->rchild;
		}
		else
		{
			return;
		}
	}	
	node* newnode = createnode(data);
	if(newnode->data < curnode->data) curnode->lchild = newnode;
	else curnode->rchild = newnode;
}

node* find_largest(node* curnode)
{
	if(curnode->rchild->rchild == NULL) return curnode;
	else return find_largest(curnode->rchild);
}
node* find_smallest(node* curnode)
{
	if(curnode->lchild->lchild == NULL) return curnode;
	else return find_smallest(curnode->lchild);
}

void delete_node(int data)
{
	if(root == NULL) return;
	node* curnode = root;
	while(curnode != NULL)
	{
		if(curnode->data == data) break;
		else if(curnode->data < data) curnode = curnode->rchild;
		else curnode = curnode->lchild;
	}
	if(curnode == NULL) return;
	
	// find out either the largest node in the left subtree or smallest node in right subtree of curnode
	if(curnode->lchild == NULL && curnode->rchild == NULL)
	{
		if(curnode == root)
		{
			root = NULL;
			free(curnode);
		}
		else
		{
			node* curnode2 = root;
			while(curnode2 != NULL)
			{
				if(curnode2->data < data)
				{
					if(curnode2->rchild == curnode) break;
					else curnode2 = curnode2->rchild;
				}
				else
				{
					if(curnode2->lchild == curnode) break;
					else curnode2 = curnode2->lchild;
				}
			}
			if(curnode2->rchild == curnode)
			{
				curnode2->rchild = NULL;
				free(curnode);
			}
			else
			{
				curnode2->lchild = NULL;
				free(curnode);
			}
		}
		return;
	}
	if(curnode->lchild != NULL)
	{
		// find largest node in left subtree's parent
		if(curnode->lchild->rchild == NULL)
		{
			curnode->data = curnode->lchild->data;
			curnode->lchild = NULL;
			return;
		}
		node* todel = find_largest(curnode->lchild);
		curnode->data = todel->rchild->data;
		todel->rchild = NULL;
		//~ free(todel);
	}
	else
	{
		// find smallest node in right subtree's parent
		if(curnode->rchild->lchild == NULL)
		{
			curnode->data = curnode->rchild->data;
			curnode->rchild = NULL;
			return;
		}
		node* todel = find_smallest(curnode->rchild);
		curnode->data = todel->lchild->data;
		todel->lchild = NULL;
		//~ free(todel);
	}
}

void print_tree(node* curnode)
{
	// inorder traversal
	if(curnode == NULL) return;
	printf("%d ", curnode->data);
	print_tree(curnode->lchild);
	print_tree(curnode->rchild);
}

int main()
{
	printf("Press 1 to insert data and 2 to delete data from tree.\n");
	printf("Press any other key to exit.\n");
	while(1)
	{
		printf("Enter your choice (1 or 2):\n");
		int choice;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter data to insert:\n");
				int data;
				scanf("%d", &data);
				insert_node(data);
				printf("Current state of tree = ");
				print_tree(root);
				printf("\n");
				break;
			}
			case 2:
			{
				printf("Enter data to remove:\n");
				int data;
				scanf("%d", &data);
				delete_node(data);
				printf("Current state of tree = ");
				print_tree(root);
				printf("\n");
				break;
			}
			default:
			{
				exit(0);
			}
		}
	}
	return 0;
}
