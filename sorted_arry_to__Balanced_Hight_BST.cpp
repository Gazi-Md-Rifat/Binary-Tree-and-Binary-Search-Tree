#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int data;
    Tree *left;
    Tree *right;
    Tree(int n) // constructor.
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};



// ------------------------------------------- Balanced Height BST -------------------------------
Tree *balanced_height(int arr[], int start, int end){

    if (start > end){
        return NULL;
    }
    int mid = (start + end) / 2;
    Tree *root = new Tree(arr[mid]);
    root->left = balanced_height(arr,start, mid - 1);
    root->right = balanced_height(arr, mid + 1, end);

    return root;
}
// --------------------------- Print Function -----------------------
void preorder(Tree *root){
    if (root == NULL){
        cout << "NULL" << " "; // for clarity with my guesing ans 4 - 1- null- null - 2 - 5 - null - 7- null - null;
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
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

    int arr[] = {1,2,4,5,7};  // 4 - 1- null- null - 2 - 5 - null - 7- null - null;
    Tree *root = balanced_height(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    // print 
    preorder(root); cout << endl;
    inorder(root);


    return 0;
}