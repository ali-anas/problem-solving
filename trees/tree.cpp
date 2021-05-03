#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this -> data = data;
	}

	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
};


TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(!pendingNodes.empty()) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			front -> children.push_back(childNode);
			pendingNodes.push(childNode);
		}
	}

	return root;
}

int sumOfNodes(TreeNode<int>* root) {
	if(root == NULL) {
		return 0;
	}

	int sum = 0;
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		sum += front->data;
		for(int i = 0; i < front->children.size(); i++) {
			pendingNodes.push(front->children[i]);
		}
	}

	return sum;
}

int numOfLeafNodes(TreeNode<int>* root) {
	if(root == NULL) {
		return 0;
	}

	if(root -> children.size() == 0) return 1;

	int count = 0;
	for(int i = 0; i < root->children.size(); i++) count += numOfLeafNodes(root->children[i]);

	return count;
}

void printLevelWise(TreeNode<int>* root) {
	if(root == NULL) {
		return;
	}

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << ": ";
		for(int i = 0; i < front->children.size(); i++) {
			cout << front->children[i]->data << " ";
			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

void postOrder(TreeNode<int>* root) {
	if(root == NULL) return;

	for(int i = 0; i < root->children.size(); i++) postOrder(root -> children[i]);

	cout << root -> data << " ";
	return;
}

int countGreaterThanX(TreeNode<int>* root, int x) {
	if (root == NULL) return 0;

	int count = 0;
	for(int i = 0; i < root -> children.size(); i++) {
		count += countGreaterThanX(root -> children[i], x);
	}
	if(root -> data > x) count++;

	return count;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
	if(root == NULL) return root;
	int ans = root -> data;
	for(int i = 0; i < root->children.size(); i++) {
		ans += root->children[i]->data;
	}

	TreeNode<int>* ansNode = root;
	for(int i = 0; i < root->children.size(); i++) {
		TreeNode<int>* maxChildNode = maxSumNode(root->children[i]);
		int maxSumChild = maxChildNode->data;
		for(int j = 0; j < maxChildNode->children.size(); j++) {
			maxSumChild += maxChildNode->children[j]->data;
		}

		if(maxSumChild > ans) {
			ans = maxSumChild;
			ansNode = maxChildNode;
		}
	}

	return ansNode;
}


int main() {
	TreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);

	cout << "Sum of Nodes: " << sumOfNodes(root) << endl;

	cout << "No of leaf Nodes: " << numOfLeafNodes(root) << endl;

	postOrder(root);

	cout << "Greater than X: " << countGreaterThanX(root, 15) << endl;

	return 0;
}