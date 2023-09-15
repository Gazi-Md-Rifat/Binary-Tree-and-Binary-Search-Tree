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

void sum_replacement(Tree *root) // Time complexcity is.......... O(N)...
{
	if (root == NULL)
	{
		return;
	}
	sum_replacement(root->left);
	sum_replacement(root->right);
	if (root->left != NULL)
	{
		root->data += root->left->data;
		if (root->right != NULL)
		{
			root->data += root->right->data;
		}
	}
}
// replaceing  process || final tree after sum replace...
/*      27+5+7             39
		/   \             /  \
   10+6+11   7           27   7
	 / \                /  \
	10  11             10  11
*/

void preorder_traversel(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder_traversel(root->left);
	preorder_traversel(root->right);
}

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

	cout << "Before Sum-Replacement Tree : ";
	preorder_traversel(node);
	cout << endl
		 << endl;
	sum_replacement(node); // sum replace functiion...
	cout << "After Sum-Replacement Tree : ";
	preorder_traversel(node);

	return 0;
}