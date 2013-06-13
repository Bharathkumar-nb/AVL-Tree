#include "avl_tree.h"

void init(Tree_t* t)
{
	t->root = NULL;
}

void make(Tree_t* t, int val)
{
	Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
	temp->key = val;
	temp->left = temp->right = NULL;
	t->root = insert(t->root, temp);
}

Node_t* insert(Node_t *root, Node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(temp->key < root->key)
	{
		root->left = insert(root->left, temp);
		root = balance(root);
	}
	else
	{
		root->right = insert(root->right, temp);
		root = balance(root);
	}
	return root;
}

Node_t* balance(Node_t* node)
{
	if(node)
	{
		Node_t* par, *cur;
		par = node;
		int par_bf = height(par->left) - height(par->right);
		int cur_bf;
		if (par_bf >1)
		{
			cur = par->left;
			cur_bf = height(cur->left) - height(cur->right);

			if (cur_bf > 0)				// LL Rotation
			{
				par->left = cur->right;
				cur->right = par;
				node = cur;
			}
			else						// LR Rotation
			{
				node = cur->right;
				cur->right = node->left;
				par->left = node->right;
				node->right = par;
				node->left = cur;
			}
		}
		else if(par_bf < -1)
		{
			cur = par->right;
			cur_bf = height(cur->left) - height(cur->right);
			
			if(cur_bf > 0)				// RR Rotation
			{
				node = cur->left;
				cur->left = node->right;
				par->right = node->left;
				node->left = par;
				node->right = cur;
			}
			else						// RL Rotation
			{
				par->right = cur->left;
				cur->left = par;
				node = cur;
			}
		}
	}
	return node;
}

int search(Tree_t* t, int val)
{
	int found = 0;
	Node_t* temp = t->root;
	while(temp && !found)
	{
		if(temp->key == val)
			found = 1;
		else if(temp->key > val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return found;
}

int del(Tree_t* t, int val)
{
	int successful = 0;
	if(t->root)
	{
		t->root = del_node(t->root, NULL, val, &successful);
		t->root = balance(t->root);
	}
	return successful;
}

Node_t* del_node(Node_t* node, Node_t* par, int val, int* successful)
{
	Node_t* cur = node;
	if(cur)
	{
		if (cur->key == val)
		{
			*successful = 1;

			Node_t *temp = NULL, *suc;
			if(cur->left==NULL)
				temp = cur->right;
			else if(cur->right==NULL)
				temp = cur->left;
			else
			{
				suc = cur->right;
				while(suc->left!=NULL)
				{
					suc = suc->left;
				}
				suc->left = cur->left;
				temp = cur->right;
			}
			if(par)
			{
				if(node == par->left)
					par->left = temp;
				else
					par->right = temp;
			}
			free(cur);
			cur = NULL;
			return temp;
		}
		else if(cur->key > val)
		{
			node->left = del_node(cur->left, cur, val, successful);
		}
		else
		{
			node->right = del_node(cur->right, cur, val, successful);
		}
		node = balance(node);
	}
	return node;
}

void clear_tree(Tree_t* t)
{
	free_node(t->root);
	t->root = NULL;
}

void free_node(Node_t* root)
{
	if(root != NULL)
	{
		free_node(root->left);
		free_node(root->right);
		free(root);
		root = NULL;
	}
}

void display(Tree_t* t)
{
	if(t->root)
	{
		//inorder_disp(t->root);
		preorder_disp(t->root);
		printf("\n");
	}
	else
	{
		printf("\nTree empty.\n");
	}
}

void inorder_disp(Node_t* root)
{
	if(root != NULL)
	{
		inorder_disp(root->left);
		int bf = height(root->left) - height(root->right);
		printf("(%d , %d)\t", root->key, bf);
		inorder_disp(root->right);
	}
}

void preorder_disp(Node_t* root)
{
	if(root != NULL)
	{
		int bf = height(root->left) - height(root->right);
		printf("(%d , %d)\t", root->key, bf);
		preorder_disp(root->left);
		preorder_disp(root->right);
	}
}

int height(Node_t* root)
{
	if(root == NULL)
		return -1;
	return 1 + max(height(root->left) , height(root->right));
}

int max(int a,int b)
{
	return (a>b)?a:b;
}