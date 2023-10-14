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

// ----------ZigZag Traversel Function -----------------My Implementatin -------------------
// ZigZag means once node tavel left to right and then once right to left and again same ..
void zigZagTraversel(Tree *root){
    
    deque<Tree*> value;
    value.push_back(root);
    value.push_back(NULL);
    bool indicator = true;
    
    while(!value.empty()){ // never container will empty because we don't pop when we get NULL as data..thats why out container never will empty.
        int n = value.size();
        if (n == 1){ // we just out of this loop from here.becaue when we have just null and no other value thats mean we compleate out all node and our container have only NULL .which we never pop..thats mean out container size is 1..when we ge n == 1 then we understod our travel is complete and we break this loop.
            break;
        }
        for (int i = 0; i < n; i++){
            if (indicator == true){
                Tree *temp = value.front();
                if (!temp){
                    cout << "N" << " "; // level done
                    indicator = !indicator;
                    break;
                }
                cout << temp->data << " "; // print
                value.pop_front();
                if (temp->left){
                    value.push_back(temp->left);
                }
                if (temp->right){
                    value.push_back(temp->right);
                }
            }

            if (indicator == false){
                Tree *temp = value.back();
                if (!temp){
                    cout << "N" << " "; // level done
                    indicator = !indicator;
                    break;
                }
                cout << temp->data << " "; // print
                value.pop_back();
                if (temp->right){
                    value.push_front(temp->right);
                }
                if (temp->left){
                    value.push_front(temp->left);
                }
            }
        }
    }


}

// ------------------------------------- Apna collage implementation -------------------------------

// ---------------------------print function -------------------------------------
void inorder(Tree *root){

    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Tree *root){

    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main ()
{

    Tree *root = NULL;
    // int arr[] = {5,2,1,4,7};
    int arr[] = {10,5,3,1,4,8,7,9,15,12,16};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        root = buildBST(root, arr[i]);
    }

    // print BST
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;

/*
                                          10 -- level 0
                                         /  \ 
                                        5    15 -- level 1
                                       / \  /  \     
                                      3   8 12  16 -- level 2
                                     / \  / \
                                    1  4 7  9  -- level 3

                                    ZigZag sequence : 10 15 5 3 6 12 16 9 7 4 1 
*/

    zigZagTraversel(root);
    // inorder(root);


    return 0;
}