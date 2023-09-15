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

//........................................... Faltten function.............................

// left child atatched with root->right and actual root->right attatched with new right childs tail node.. 

/*   5                       5
	/ \                       \
   6   7                       6
    \                           \
	 10                          10
	  \                           \
	   11                          11
                                    \
                                     7
*/

void flatten_tree(Tree *root)
{
	// base case ...
	if (root == NULL || (root->left == NULL && root->right == NULL))
	{
		return;
	}

	if (root->left != NULL)
	{
		flatten_tree(root->left);

		Tree *temp = root->right; // right child store a temp variable.. for left child shift right child place and left child null..
		root->right = root->left;
		root->left = NULL;

		Tree *tail = root->right; // this child was left but we shift left to right..
		while (tail->right != NULL)
		{
			tail = tail->right;
		}
		// when we come out of this loop then we found tail at right child..

		// Now our actual right child what i  stored temp variable, attatched with tail ..
		tail->right = temp;
	}
	flatten_tree(root->right);

}

//............................... print data in_order sequence .............................
void inorder_sequence(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_sequence(root->left);
	cout << root->data << " " ;
	inorder_sequence(root->right);
}

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

	// actual data..
	inorder_sequence(node);
	cout << endl;
	
	// print after flatten..
	flatten_tree(node);
	inorder_sequence(node);


	return 0;
}