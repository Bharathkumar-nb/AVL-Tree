#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
};
typedef struct Node Node_t;

struct Tree
{
	Node_t* root;
};
typedef struct Tree Tree_t;

void init(Tree_t* );
void make(Tree_t*, int);
Node_t* insert(Node_t *, Node_t* );
Node_t* balance(Node_t* );
int search(Tree_t*, int);
void display(Tree_t*);
void inorder_disp(Node_t*);
void preorder_disp(Node_t*);
int del(Tree_t*, int);
Node_t* del_node(Node_t* ,Node_t*, int, int*);
void clear_tree(Tree_t*);
void free_node(Node_t*);
int height(Node_t* );
int max(int ,int );


#endif