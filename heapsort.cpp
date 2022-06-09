#include <iostream>

using namespace std;

struct node
{
	int val;
	node* L;
	node* R;
	node* up;
};

void insertBST(node* &root, int x, node* &up)
{
	if (root == NULL) {
		root = new node;
		root->val = x;
		root->R = root->L = NULL;
		root->up = up;
	}
	else {
		if (x < root->val) {
			insertBST(root->L, x, root);
		}
		else {
			insertBST(root->R, x, root);
		}
	}
}

void inOrder(node* root) {
	if (root != NULL) {
		inOrder(root->L);
		cout << root->val << " ";
		inOrder(root->R);
	}
}

node* find(node* root, int _element) {
	if (root != NULL) {
		find(root->L, _element);
		if(root->val == _element) {
			cout << root->val << " ";
			return root;
		}
		find(root->R, _element);
	}
}

void findEvenNumbers(node* root) {
	if (root != NULL) {
		findEvenNumbers(root->L);
		if(root->val % 2 == 0) {
			cout << root->val << " ";
		}
		findEvenNumbers(root->R);
	}
}

void findMin(node*& root, node*& min)
{
	if (root != NULL) {
		if (root->L != NULL) {
			findMin(root->L, min);
		}
		else {
			min = root;
		}
	}
}

void findMax(node*& root, node*& max)
{
	if (root != NULL) {
		if (root->R != NULL) {
			findMin(root->R, max);
		}
		else {
			max = root;
		}
	}
}

void findSuccessor(node* &root, node* &successor) {
	if (root != NULL) {
		if (root->R != NULL) {
			findMin(root->R, successor);
		}
		else if (root->up != NULL && root->up->L == root) {
			successor = root->up;
		}
		else {
			successor = NULL;
		}
	}
}

void findPredecessor(node*& root, node*& predecessor)
{
	if (root != NULL)
	{
		if (root->L != NULL) findMax(root->L, predecessor);
		else if (root->up != NULL && root->up->R == root) predecessor = root->up;
		else predecessor = NULL;
	}
}


node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->L != NULL)
		current = current->L;

	return current;
}

node* deleteNode(node* root, int _val)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (_val < root->val)
		root->L = deleteNode(root->L, _val);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (_val > root->val)
		root->R = deleteNode(root->R, _val);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->L == NULL and root->R == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->L == NULL) {
			node* temp = root->R;
			delete root;
			return temp;
		}
		else if (root->R == NULL) {
			node* temp = root->L;
			delete root;
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		node* temp = minValueNode(root->R);

		// Copy the inorder successor's content to this node
		root->val = temp->val;

		// Delete the inorder successor
		root->R = deleteNode(root->R, temp->val);
	}
	return root;
}

int main() {
	node* root = NULL;
	node* up = NULL;

	node* max = NULL;
	node* min = NULL;
	node* successor = NULL;
	node* predecessor = NULL;

	insertBST(root, 13, up);
	insertBST(root, 15, up);
	insertBST(root, 8, up); 
	insertBST(root, 10, up); 
	insertBST(root, -3, up); 
	insertBST(root, 9, up); 
	insertBST(root, 2, up); 

	inOrder(root);

	cout << endl << "+=========+" << endl;
	node* sample = find(root, 10);

	cout << endl << "+=========+" << endl;

	findEvenNumbers(root);
	cout << endl << "+=========+" << endl;

	findMin(root, min);
	cout << min->val;
	cout << endl << "+=========+" << endl;

	findMax(root, max);
	cout << max->val;
	cout << endl << "+=========+" << endl;

	findSuccessor(root->L->R->L, successor);
	cout << endl << "+=========+" << endl;
	if (successor != NULL) {
		cout << "Nastepnik " << root->L->R->L->val << " to: " << successor->val << endl;
	}


	cout << endl << "+=========+" << endl;
	deleteNode(root, 8);
	cout << endl << "+=========+" << endl;
	inOrder(root);


	return 0;
}