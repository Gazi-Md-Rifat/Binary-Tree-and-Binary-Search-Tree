#include <bits/stdc++.h>
using namespace std;

struct Tree
{
	int data;
	Tree *left;
	Tree *right;
	Tree(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
	Tree() 
	{
		// Default Constructor...
	};
};

/*     5
	 /  \
	2    7
   / \
  1   4
*/
// preorder sequence : 5 2 1 4 7
// inorder sequence : 1 2 4 5 7
// postorder sequence : 1 4 2 7 5

// --------------------------------- Function for BST ---------------------------------

Tree *Build_BST(Tree *root, int value){
	if (root == NULL){
		return new Tree(value);
	}
	if (root->data > value){
		root->left = Build_BST(root->left, value);
	}
	else { // root->data < value;
		root->right = Build_BST(root->right, value);
	}
	return root;
}


// -------------------------------------- Print function ------------------------------------
void postorder_traversel(Tree *node){
	if (node == NULL)
	{
		return;
	}
	postorder_traversel(node->left);
	postorder_traversel(node->right);
	cout << node->data << " ";
}

void inorder_traversel(Tree *node){
	if (node == NULL)
	{
		return;
	}
	inorder_traversel(node->left);
	cout << node->data << " ";
	inorder_traversel(node->right);
}

void preorder_traversel(Tree *node){
	if (node == NULL)
	{
		return;
	}
	cout << node->data << " ";
	preorder_traversel(node->left);
	preorder_traversel(node->right);
}

int main()
{
	Tree *node = NULL;
	node = Build_BST(node, 5);
	Build_BST(node, 2);
	Build_BST(node, 1);
	Build_BST(node, 4);
	Build_BST(node, 7);
	cout << "BST in preorder sequence : " ;
	preorder_traversel(node);
	cout << endl << "BST in inorder sequence : ";
	inorder_traversel(node);
	cout << endl << "BST in postorder sequence : ";
	postorder_traversel(node);
	
	
	return 0;
}