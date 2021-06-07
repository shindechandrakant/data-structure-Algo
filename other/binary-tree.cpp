#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

struct tree {
	int data;
	tree *left = NULL, *right = NULL;
};

tree * createTree() {

	int data;
	cin>>data;
	if(data == 0) return NULL;
	tree *t = new tree;
	t -> data = data;
	t -> left = createTree();
	t -> right = createTree();
	return t;
}

void displayTree(tree * root) {

	if(root == NULL) return;
	displayTree(root -> left);
	cout<<root -> data<<" ";
	displayTree(root -> right);
}

int height(tree *root) {

	if(root == NULL) return -1;
	int left = height(root -> left);
	int right = height(root -> right);
	return (left > right ? left : right) + 1;
}

int diameter(tree *root) {

	if(root == NULL) return 0;

	int left = diameter(root -> left);
	int right = diameter(root -> right);
	int hight = height(root -> left) + height(root -> right) + 2;

	left = max(left, right);
	return max(left, hight);
}


int main()
{

	tree *root = createTree();
	displayTree(root);
	cout<<"\n\nHeight of Tree "<<height(root);
	cout<<"\n\nDiameter : "<<diameter(root);
}
