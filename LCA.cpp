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

bool getpath(Tree *root, vector<int> &path, int key)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }
    if (getpath(root->left, path, key) || getpath(root->right, path, key))
    {
        return true;
    }
    path.pop_back();
}

int lca(Tree *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!getpath(root, path1, n2) ||! getpath(root, path2, n2))
    {
        return -1;
    }
    int i = 0;
    for (i; i < path1.size() && path2.size(); i++)
    {
        if (path1[i] != path2[i])
        {
            break;
        }
    }

    return path1[i - 1]; // or path2[i - 1];
}

// ------------------------------------------- OPTIMIZED CODE ------------------------------

Tree* LCA(Tree *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Tree *leftLCA = LCA(root->left, n1, n2);
    Tree *rightLCA = LCA(root->right, n1, n2);
    
    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
}


int main()
{
	Tree *node = new Tree(5);
	node->left = new Tree(6);
	node->right = new Tree(7);
	node->left->left = new Tree(10);
	node->left->right = new Tree(11);

    cout << LCA(node, 10, 11)->data << endl;
    cout << lca(node, 10, 11);
	

	return 0;
}