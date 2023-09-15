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
	6    7
   / \
  10  11
*/
// preorder sequence : 5 6 10 11 7
// inorder sequence : 10 6 11 5 7
// postorder sequence : 10 11 6 7 5

void postorder_traversel(Tree *node)
{
	if (node == NULL)
	{
		return;
	}
	postorder_traversel(node->left);
	postorder_traversel(node->right);
	cout << node->data << " ";
}

void inorder_traversel(Tree *node)
{
	if (node == NULL)
	{
		return;
	}
	inorder_traversel(node->left);
	cout << node->data << " ";
	inorder_traversel(node->right);
}

void preorder_traversel(Tree *node)
{
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
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);
	cout << "Preorder Traversel Data : ";
	preorder_traversel(node);
	cout << endl
		 << endl;
	cout << "Inorder Traversel Data : ";
	inorder_traversel(node);
	cout << endl
		 << endl;
	cout << "Postorder Traversel Data : ";
	postorder_traversel(node);
	cout << endl;

	return 0;
}