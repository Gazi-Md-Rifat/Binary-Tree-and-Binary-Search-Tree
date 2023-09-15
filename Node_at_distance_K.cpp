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
   / \    \
  10  11   20
     /  \ 
	15   14

*/
// preorder sequence : 5 6 10 11 7
// inorder sequence : 10 6 11 5 7
// postorder sequence : 10 11 6 7 5

// -------------------------------- sub tree traverse case ------------------------------------
void print_K_distance(Tree *root, int k){
	if (k < 0){
		return;
	}
	if ( k == 0){
		cout << root->data << " " ;
		// return;
	}
	print_K_distance(root->left, k - 1);
	print_K_distance(root->right, k - 1);
}
void find_target(Tree *root, int target, int k){
	if (root == NULL){
		return;
	}
	if (root->data == target){
		print_K_distance(root, k);
	}
	find_target(root->left, target, k);
	find_target(root->right, target, k);
}

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

	find_target(node, 5, 2);



	return 0;
}