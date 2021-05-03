#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this -> data = data;
		left = NULL;
		right = NULL;
	}
};

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cin >> rootData;

	if(rootData == -1) return NULL;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>* > q;
	q.push(root);
	while(!q.empty()) {
		BinaryTreeNode<int>* front = q.front();
		q.pop();

		int leftData;
		cin >> leftData;
		if(leftData != -1) {
			BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
			front->left = leftNode;
			q.push(leftNode);
		}

		int rightData;
		cin >> rightData;
		if(rightData != -1) {
			BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
			front->right = rightNode;
			q.push(rightNode);
		}
	}

	return root;
}

void printLevelWise(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		cout << -1 << endl;
		return;
	}

	queue<BinaryTreeNode<int>* > q;
	q.push(root);
	while(!q.empty()) {
		BinaryTreeNode<int>* curr = q.front();
		q.pop();
		cout << curr -> data << ": left: ";
		if(curr -> left) {
			cout << curr -> left -> data;
			q.push(curr -> left);
		} else cout << -1;
		cout << " right: ";
		if(curr->right) {
			cout << curr -> right -> data;
			q.push(curr -> right);
		} else cout << -1;
		cout << endl;
	}
}

int getHeightOfB_Tree(BinaryTreeNode<int>* root) {
	if(root == NULL) return 0;

	int lHeight = getHeightOfB_Tree(root->left);
	int rHeight = getHeightOfB_Tree(root->right);

	return 1+max(lHeight, rHeight);
}

int main() {
	BinaryTreeNode<int>* root = takeInput();
	printLevelWise(root);

	cout << "Height: " << getHeightOfB_Tree(root) << endl;


	return 0;
}