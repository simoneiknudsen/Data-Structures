#ifndef __tree_h
#define __tree_h

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

typedef struct Tree {
	int size;
	struct Node *root;
} Tree;

bool isEmpty(Tree *tree);
void inorderTreeWalk(Node *node);
Node *search(Node *node, int searchKey);
void insert(Tree *t, int k);
void transplant(Tree *t, Node *u, Node *v);
void delete(Tree *t, Node *z);
Node *minimum(Node *x);

#endif