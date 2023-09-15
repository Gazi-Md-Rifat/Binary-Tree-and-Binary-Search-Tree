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

int length_of_tree(Tree *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left_child = length_of_tree(root->left);
	int righ_child = length_of_tree(root->right);
	int length = max(left_child, righ_child) + 1;

	return length;
}

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

	cout << "Length of the Tree : " << length_of_tree(node);

	return 0;
}