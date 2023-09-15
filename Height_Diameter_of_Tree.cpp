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

// .........................................Height Function ......................................
int height_of_tree(Tree *root) // Time Complexcity -->> O(N)...
{
	if (root == NULL)
	{
		return 0;
	}

	return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
}

// ................................. Diameter Function ...........................................
int calcualtion_height(Tree *root) // stuf function...
{
	if (root == NULL)
	{
		return 0;
	}

	return max(calcualtion_height(root->left), calcualtion_height(root->right)) + 1;
}

int diameter_of_tree(Tree *root) // Time Complexcity -->> O(N^2)..   Recoursive call for N time .. Stuf functiion perform N time for single recoursive call... That's mean O(n^N) == O(N^2)...
{
	if (root == NULL)
	{
		return 0;
	}
	// stuf function...
	int left_height = calcualtion_height(root->left);
	int right_height = calcualtion_height(root->right);
	int curr_diameter = left_height + right_height + 1;
	// recoursive call...
	int left_diameter = diameter_of_tree(root->left);
	int right_diameter = diameter_of_tree(root->right);

	return max(curr_diameter, max(left_diameter, right_diameter));
}

// ...................................... Optimize Code For Diameter Calculation......................
// ...................................... Apna Collage...................................

int calculate_diameter(Tree *root, int *height)
{
	if (root == NULL)
	{
		*height = 0;
		return 0;
	}
	int l_h = 0, r_h = 0;
	int left_diameter = calculate_diameter(root->left, &l_h);
	int right_diameter = calculate_diameter(root->right, &r_h);
	int curr_diameter = l_h + r_h + 1;
	*height = max(l_h, r_h) + 1;
	return max(curr_diameter, max(left_diameter, right_diameter));
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

	cout << "Tree Height is : " << height_of_tree(node) << endl;
	cout << "Tree Diameter is : " << diameter_of_tree(node) << endl;
	int height = 0;
	cout << "OPTIMIZZE CODE FOR DIAMETER : " << calculate_diameter(node, &height);

	return 0;
}