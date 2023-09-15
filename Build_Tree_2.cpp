#include <bits/stdc++.h>
using namespace std;

// Build Tree using Inorder and Postorde sequence....

//................................................STRUCT............................

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
		// Default Constructor.....
	}
};

//.........................................VISUAL TREE.......................................

/*     5
	 /  \
	6    7
   / \
  10  11
*/
// preorder sequence : 5 6 10 11 7
// inorder sequence : 10 6 11 5 7
// postorder sequence : 10 11 6 7 5

//..................................BUILD TREE ............................................

int search_position(int inorder[], int start, int end, int current)
{
	for (int i = start; i <= end; i++)
	{
		if (inorder[i] == current)
		{
			return i;
		}
	}

	return -1;
}

Tree *Build_Tree(int postorder[], int inorder[], int start, int end)
{
	static int idx = end;
	if (start > end)
	{
		return NULL;
	}
	int current = postorder[idx];
	idx--;
	Tree *root = new Tree(current);
	if (start == end)
	{
		return root;
	}
	int possition = search_position(inorder, start, end, current);
	root->right = Build_Tree(postorder, inorder, possition + 1, end);
	root->left = Build_Tree(postorder, inorder, start, possition - 1);
	

	return root;
}

// ......................................PRINT FUNCTION............................................

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

void inorder_traversel(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder_traversel(root->left);
	cout << root->data << " ";
	inorder_traversel(root->right);
}

void postorder_traversel(Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder_traversel(root->left);
	postorder_traversel(root->right);
	cout << root->data << " ";
}

// ...............................MAIN FUNCTION..................................

int main()
{
	int postorder_sequence[] = {10, 11, 6, 7, 5};
	int inorder_sequence[] = {10, 6, 11, 5, 7};
	int start = 0, end = (sizeof(inorder_sequence) / sizeof(inorder_sequence[0])) - 1;

	Tree *head = Build_Tree(postorder_sequence, inorder_sequence, start, end);

	cout << "Printed Data in PREORDER sequence : ";
	preorder_traversel(head);
	cout << endl
		 << endl;
	cout << "Printed Data in INORDER sequence : ";
	inorder_traversel(head);
	cout << endl
		 << endl;
	cout << "Printed Data in POSTORDER sequence : ";
	postorder_traversel(head);
	cout << endl
		 << endl;

	return 0;
}