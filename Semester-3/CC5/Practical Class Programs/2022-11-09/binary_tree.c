#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
} node;

int n;
int adj_mat[MAX_NODES][MAX_NODES];
int children[MAX_NODES];

node* create_node(int num)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = num;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
}

node* create_tree(int node_idx)
{
	node* newnode = create_node(node_idx);
	for(int i = 1; i <= n; i++)
	{
		if(adj_mat[node_idx][i])
		{
			node* child = create_tree(i);
			if(newnode->lchild == NULL) newnode->lchild = child;
			else newnode->rchild = child;
		}
	}
	return newnode;
}

void print_tree(node* curnode)
{
	printf("curnode = %d\n", curnode->data);
	if(curnode->lchild != NULL)
	{
		printf("left child of %d is %d\n", curnode->data,curnode->lchild->data);
	}
	if(curnode->rchild != NULL)
	{
		printf("right child of %d is %d\n", curnode->data,curnode->rchild->data);
	}
	if(curnode->lchild != NULL) print_tree(curnode->lchild);
	if(curnode->rchild != NULL) print_tree(curnode->rchild);
}

int main()
{
	printf("Enter the number of nodes in the tree:\n");
	scanf("%d",&n);
	
	printf("Enter the edges in the binary tree:\n");
	for(int i = 0; i < n-1; i++)
	{
		while(1)
		{
			printf("Enter the nodes to be connected with an edge:\n");
			int u,v;
			scanf("%d%d",&u,&v);
			if(u < 1 || v < 1 || u > n || v > n)
			{
				printf("Invalid node number. Please enter again.\n");
			}
			else if(children[u] == 2)
			{
				printf("%d already has 2 children. Please enter again.\n", u);
			}
			else
			{
				children[u]++;
				adj_mat[u][v] = 1;
				break;
			}
		}
	}
	
	node* root = create_tree(1);
	print_tree(root);
	return 0;
}
