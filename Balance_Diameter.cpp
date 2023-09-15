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
	Tree(){
		// Default Constructor...
	};
};

/*     5
	 /  \
	6    7
   / \
  10  11
*/

int height(Tree *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh, rh) + 1;
}

bool isbalanced(Tree *root)
{
	if (root == NULL)
	{
		return true;
	}
	if (isbalanced(root->left) == false)
	{
		return false;
	}
	if (isbalanced(root->right) == false)
	{
		return false;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	if (abs(lh - rh) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);
	// add new data for check tree...
	node->left->right->right = new Tree(100); // if i add this line then my tree will be Un-Balanced...
	if (isbalanced(node))
	{
		cout << "BALANCED";
	}
	else
	{
		cout << "UN-BALANCED";
	}

	return 0;
}