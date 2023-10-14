#include <bits/stdc++.h>
using namespace std;

// BST search for time complexity is O(long n);
// because i don't need traverse each node.. i just traverse left child or right child according to coparision..

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

// ---------------------------------Build Function for BST ---------------------------------

Tree *Build_BST(Tree *root, int value){
	if (root == NULL){
		return new Tree(value);
	}
	if (root->data > value){
		root->left = Build_BST(root->left, value);
	}
	else {
		root->right = Build_BST(root->right, value);
	}
	return root;
}
// ------------------------------------------------ search functiion in BST --------------
Tree *find_key(Tree *root, int key){
    if (root == NULL){
        return NULL; // condition wise. it can be like -1.
    }
    if (root->data == key){
        return root;
    }
    if (root->data > key){
        return find_key(root->left, key);
    }
    // root->data < key for else case or direct return.
    return find_key(root->right, key);
}

// ------------------------------------- bool type function -------------------------

bool find_k(Tree *root, int key){
    if (root == NULL){
        return false;
    }
    if (root->data == key){
        return true;
    }
    if (root->data > key){
        return find_k(root->left, key);
    }
    // root->data < key for else case or direct return.
    return find_k(root->right, key);
}

// --------------------------------Delete funtion -------------------------------------
Tree *inorder_succecor(Tree *root){ // stuf function for find inorder sequence
    Tree *curr = root;
    while (curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Tree *delete_key(Tree *root, int key){ // main delete function
    if (root->data > key){
        root->left = delete_key(root->left, key);
    }
    else if (root->data < key){
        root->right = delete_key(root->right, key);
    }
    else {

        if (root->left == NULL){
            Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        else {
            Tree *temp = inorder_succecor(root->right); // call for next element after root->data through inorder sequence..
            root->data = temp->data;
            root->right = delete_key(root->right, temp->data); // then set the temp data for key..and call delete the key..note ->> delete function call after the root->right.
        }
    }
    return root;
}
// ----------------------------- Print function ----------------------
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
	Tree *node = NULL;
	node = Build_BST(node, 5);
	Build_BST(node, 2);
	Build_BST(node, 1);
	Build_BST(node, 4);
	Build_BST(node, 7);
    // search statement
    cout << "first one : ";
    if (find_key(node, 8) == NULL){
        cout << "key does not esit" << endl;
    }
    else {
        cout << "key exit" << endl;
    }
    cout << "second one : ";
    if (find_k(node, 7)){
        cout << "key exit" << endl;
    }
    else {
        cout << "key does not exit" << endl;
    }
    // delete statement;
    inorder(node);// without delete;
    cout << endl;
    delete_key(node, 2);// delete function
    inorder(node);


	return 0;
}