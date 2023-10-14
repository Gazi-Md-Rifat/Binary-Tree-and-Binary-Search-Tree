#include<iostream>
#include<queue>
#include<deque>
using namespace std;

struct Tree {

    int data;
    Tree *left;
    Tree *right;
    Tree(int value){    
        data = value;
        left = NULL;
        right = NULL;
    }
};

// ---------------------------- BUILD BST ------------------------------

Tree *buildBST(Tree *root, int key){

    if (root == NULL){
        return new Tree(key);
    }
    if (root->data > key){
        root->left = buildBST(root->left, key);
    }
    else {// root->data < key
        root->right = buildBST(root->right, key);
    }

    return root;
}

// ----------------------------------Identical BST Check Function ------------------------------------

bool checkIdenticalBST(Tree *root_1, Tree *root_2){
    static int idx = 0;
    if (!root_1 && !root_2){
        return true;
    }
    else if(!root_1 || !root_2){
        return false;
    }

    if (root_1->data == root_2->data){
        return (checkIdenticalBST(root_1->left, root_2->left) && checkIdenticalBST(root_1->right, root_2->right));
    }
    return false;
}




// ---------------------------print function -------------------------------------
void inorder(Tree *root){

    if (root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
}

int main ()
{
    // BSt 01 and BST 04 are same ..
    // BST 01
    Tree *root_1 = NULL;
    int arr_1[] = {5,2,1,4,7};
    for (int i = 0; i < sizeof(arr_1) / sizeof(arr_1[0]); i++){
        root_1 = buildBST(root_1, arr_1[i]);
    }
    // BST 01
    Tree *root_2 = NULL;
    int arr_2[] = {5,2,1,4,7};
    for (int i = 0; i < sizeof(arr_2) / sizeof(arr_2[0]); i++){
        root_2 = buildBST(root_2, arr_2[i]);
    }

    if (checkIdenticalBST(root_1, root_2)){
        cout << "BST is Identical";
    }
    else{
        cout << "BST is Not Identical";
    }


cout << endl;

// check using not same BST

// BSt 01 and BST 04 are not same ..
    // BST 03
    Tree *root_3 = NULL;
    int arr_3[] = {5,2,1,4,6};
    for (int i = 0; i < sizeof(arr_3) / sizeof(arr_3[0]); i++){
        root_3 = buildBST(root_3, arr_3[i]);
    }
    // BST 04
    Tree *root_4 = NULL;
    int arr_4[] = {5,2,1,3,7};
    for (int i = 0; i < sizeof(arr_4) / sizeof(arr_4[0]); i++){
        root_4 = buildBST(root_4, arr_4[i]);
    }

    if (checkIdenticalBST(root_3, root_4)){
        cout << "BST is Identical";
    }
    else{
        cout << "BST is Not Identical";
    }


    return 0;
}