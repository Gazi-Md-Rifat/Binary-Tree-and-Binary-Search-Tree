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
	2    7
   / \
  1   4
*/
// preorder sequence : 5 2 1 4 7
// inorder sequence : 1 2 4 5 7
// postorder sequence : 1 4 2 7 5

// --------------------------------- Function for Preorder to BST ---------------------------------

Tree *preorder_to_BST(Tree *root, int key){
    if (root == NULL){
        return new Tree(key);
    }
    if (root->data > key){
        root->left = preorder_to_BST(root->left, key);
    }
    else { // root->data < key
       root->right = preorder_to_BST(root->right, key);
    }
    return root;
}
// ---------------------------------- apna collage logic ---------------------------------------

Tree *construct_BST(int preorder[], int *preorderIdx, int key, int min, int max, int n){ // time complexity O(long n);
    if (*preorderIdx >= n){
        return NULL;
    }
    Tree *root = NULL;
    if (key > min && key < max){
        root = new Tree(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n){
            root->left = construct_BST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n){
            root->right = construct_BST(preorder, preorderIdx, preorder[*preorderIdx],key, max, n);
        }
    }

    return root;
}

// -------------------------------- Check BST ----------------------------
bool isBST(Tree *root, Tree *min= NULL, Tree *max = NULL){ // time complexity is O(N);
    if (root == NULL){
        return true;
    }
    if (min != NULL && root->data <= min->data){
        return false;
    }
    if (max != NULL && root->data >= max->data){
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid && rightValid;
}

// ----------------------------- Print Fuction -----------------------------
void inorder(Tree *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
	int preorder[] = {5,2,1,4,7};
    // This section is my implementation
    Tree *root = NULL;
    for (int i = 0; i < sizeof(preorder) / sizeof(preorder[0]); i++){
        root = preorder_to_BST(root, preorder[i]);
    }
    inorder(root);

    cout << endl;
    // Apna collage implementation
    int preorderIdx = 0; int n = 5; // size of preorder array
    Tree *node = construct_BST(preorder, &preorderIdx, preorder[preorderIdx], INT_MIN, INT_MAX, n);
    inorder(node);

    // check bst
    cout << endl;
    if(isBST(root, NULL, NULL)){
        cout << "valid BST";
    }
    else {
        cout << "invalide BST";
    }



	return 0;
}