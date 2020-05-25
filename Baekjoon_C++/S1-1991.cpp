#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char DATATYPE;

struct TreeNode
{
	DATATYPE data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* findTree;

TreeNode* MakeTree() {
	TreeNode* tree = new TreeNode();
	tree->data = NULL;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
}

DATATYPE RetData(TreeNode* tree) {
	return tree->data;
}

void SaveData(TreeNode* tree, DATATYPE data) {
	tree->data = data;
}

TreeNode* RetSubTreeLeft(TreeNode* tree) {
	return tree->left;
}

TreeNode* RetSubTreeRight(TreeNode* tree) {
	return tree->right;
}

void MakeSubTreeLeft(TreeNode* tree, TreeNode* subtree) {
	if (tree->left != NULL) free(tree->left);
	tree->left = subtree;
}

void MakeSubTreeRight(TreeNode* tree, TreeNode* subtree) {
	if (tree->right != NULL) free(tree->right);
	tree->right = subtree;
}

void PreorderTraversal(TreeNode* tree) {
	if (tree == NULL) return;

	cout << tree->data;
	PreorderTraversal(tree->left);
	PreorderTraversal(tree->right);
}

void InorderTraversal(TreeNode* tree) {
	if (tree == NULL) return;

	InorderTraversal(tree->left);
	cout << tree->data;
	InorderTraversal(tree->right);
}

void PostorderTraversal(TreeNode* tree) {
	if (tree == NULL) return;

	PostorderTraversal(tree->left);
	PostorderTraversal(tree->right);
	cout << tree->data;
}

void FindTreeByData(TreeNode* tree, DATATYPE data) {
	if (tree == NULL) return ;
	else if (RetData(tree) == data) findTree = tree;
	
	FindTreeByData(tree->left, data);
	FindTreeByData(tree->right, data);
}

int main() {
	int n;
	char a, b, c;

	cin >> n;
	TreeNode* lemonTree = MakeTree();
	findTree = lemonTree;
	cin >> a >> b >> c;
	SaveData(lemonTree, a);
	if (b != '.') {
		MakeSubTreeLeft(lemonTree, MakeTree());
		SaveData(lemonTree->left, b);
	}
	if (c != '.') {
		MakeSubTreeRight(lemonTree, MakeTree());
		SaveData(lemonTree->right, c);
	}
	
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		FindTreeByData(lemonTree, a);
		if (findTree != NULL) {
			if (b != '.') {
				MakeSubTreeLeft(findTree, MakeTree());
				SaveData(findTree->left, b);
			}
			if (c != '.') {
				MakeSubTreeRight(findTree, MakeTree());
				SaveData(findTree->right, c);
			}
		}
	}
	
	PreorderTraversal(lemonTree);
	cout << endl;
	InorderTraversal(lemonTree);
	cout << endl;
	PostorderTraversal(lemonTree);
	cout << endl;

	return 0;
}

//form에 익숙해지자