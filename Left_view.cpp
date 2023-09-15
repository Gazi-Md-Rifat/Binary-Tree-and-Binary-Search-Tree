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

void left_view_of_tree(Tree *root)
{
	queue<Tree *> container;
	container.push(root);
	while (!container.empty())
	{
		int n = container.size();
		for (int i = 0; i < n; i++)
		{
			Tree *curr = container.front();
			container.pop();
			if (i == 0)
			{
				cout << curr->data << " ";
			}
			if (curr->left != NULL)
			{
				container.push(curr->left);
			}
			if (curr->right != NULL)
			{
				container.push(curr->right);
			}
		}
	}

	return;
}

/*     5
	 /  \
	6    7
   / \
  10  11
*/

int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

	left_view_of_tree(node);

	return 0;
}