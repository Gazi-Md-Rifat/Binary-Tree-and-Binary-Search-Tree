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
// preorder sequence : 5 6 10 11 7
// inorder sequence : 10 6 11 5 7
// postorder sequence : 10 11 6 7 5

int maximum_path_sum(Tree *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(maximum_path_sum(root->left, ans),maximum_path_sum(root->right, ans)) + root->data;
}

int main()
{
    Tree *node = new Tree(5);
    node->left = new Tree(6);
    node->right = new Tree(7);
    node->left->left = new Tree(10);
    node->left->right = new Tree(11);
    int ans = 0;
    cout << maximum_path_sum(node, ans);

    return 0;
}