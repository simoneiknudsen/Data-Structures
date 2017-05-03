#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "tree.h"

int main(){

	Tree *tree;
	tree = calloc(1,sizeof(Tree));

	if(isEmpty(tree)){
		printf("Tree is empty\n");
	}

	insert(tree,2);
	insert(tree,3);
	insert(tree,4);
	insert(tree,1);
	insert(tree,5);
	printf("Root of tree: %d\n", tree->root->key);
	inorderTreeWalk(tree->root);
	printf("\n");
	return 0;
}

bool isEmpty(Tree *tree){
	if(tree->root == NULL){
		return true;
	} else {
		return false;
	}
}

void inorderTreeWalk(Node *node){
	if(node != NULL){
		inorderTreeWalk(node->left);
		printf("%d ", node->key);
		inorderTreeWalk(node->right);
	}
}

Node *search(Node *node, int searchKey){
	if(node == NULL || searchKey == node->key){
		return node;
	} else if(searchKey < node->key){
		return search(node->left,searchKey);
	} else {
		return search(node->right,searchKey);
	}
}

void insert(Tree *T, int k){
	Node *z = calloc(1,sizeof(Node));
	z->key = k;
	Node *y = NULL;
	Node *x = T->root;
	while(x != NULL){
		y = x;
		if(z->key < x->key){
			x = x->left;
		} else {
			x = x->right;
		}
	}
	z->parent = y;
	if(y == NULL){
		T->root = z;
	} else if(z->key < y->key){
		y->left = z;
	} else {
		y->right = z;
	}
}

void transplant(Tree *T, Node *u, Node *v){
	if(u->parent == NULL){
		T->root = v;
	} else if(u == u->parent->left){
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	if(v != NULL){
		v->parent = u->parent;
	}
}

void delete(Tree *T, Node *z){
	Node *y = NULL;
	Node *x = T->root;
	if(z->left == NULL){
		transplant(T,z,z->right);
	} else if(z->right == NULL){
		transplant(T,z,z->left);
	} else {
		y = minimum(z->right);
		if(y->parent != z){
			transplant(T,y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(T,z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}

Node *minimum(Node *x){
	while(x->left != NULL){
		x = x->left;
	}
	return x;
}

