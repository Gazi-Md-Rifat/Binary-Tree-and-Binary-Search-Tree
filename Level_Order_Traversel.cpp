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

// .............................Level Order Traversel Function.........................OPTIMIZED CODE...

int level_order_traversel(Tree *root, int k)
{
	cout << "Level Oize Data : ";
	int sum = 0;
	int level = 0;
	queue<Tree *> container;
	container.push(root);
	container.push(NULL);
	while (!container.empty())
	{
		Tree *head = container.front();
		container.pop();
		if (head != NULL)
		{
			cout << head->data << " ";
			if (level == k)
			{
				sum += head->data;
			}
			if (head->left != NULL)
			{
				container.push(head->left);
			}
			if (head->right != NULL)
			{
				container.push(head->right);
			}
		}
		else if (!container.empty())
		{
			container.push(NULL);
			level++;
		}
	}
	cout << endl << endl << "K-th level data sum : " << sum;
	cout << endl
		 << "level : ";
	return level;
}

// ..........................Level Order Traversel Function ..................................
// .....MY Implementation....................

void Level_order_traversel(Tree *root)
{
	queue<Tree *> container;
	container.push(root);
	while (!container.empty())
	{
		int n = container.size();
		for(int i = 0; i < n; i++)
		{
			Tree *curr = container.front();
			container.pop();
			cout << curr->data << " ";
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
	
}

int main()
{
	int k = 1;
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);
	cout << level_order_traversel(node, k);
	cout << endl;
	Level_order_traversel(node);

	return 0;
}