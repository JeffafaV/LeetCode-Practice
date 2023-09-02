#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// struct for a node in the binary tree
struct TreeNode
{
	int val; // value of the node
	TreeNode *left; // left child node pointer
	TreeNode *right; // right child node pointer
	
	// parameterized constructor
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// creates a binary tree and returns the root of the tree
TreeNode *createBinaryTree()
{
	// create root node and initialize it to null
	TreeNode *root = NULL;
	
	// create a queue variable to hold TreeNode pointers
	// queue is necessary in order to create nodes in level order
	queue<TreeNode *> q;
	
	// used to store yes or no responses from the user
	string s;
	
	// display text and take user input
	cout << "Insert root node? y for yes or n for no: ";
	cin >> s;
	
	// user doesn't want to insert a root node
	if (s == "n")
	{
		// return null since the tree is empty
		return root;
	}
	
	// used to store a value for a node
	int val;
	
	// enter node value for root node
	cout << "Enter root node value: ";
	cin >> val;
	
	// create a new node in heap using the user's entered value and set it as the root
	root = new TreeNode(val);
	// push the root into the queue
	q.push(root);
	
	// keep looping until the queue is empty because we 
	// want to insert all the nodes into the tree and 
	// before they reach the tree they go into the queue
	while (q.size() != 0)
	{
		// used to create a new node
		TreeNode *t = NULL;
		// holds the first node in the queue
		TreeNode *p = q.front();
		// remove the first node from the queue
		q.pop();
		
		// display text and take user input
		cout << "Insert left child node for " << p->val << "? y for yes or n for no: ";
		cin >> s;
		
		// user wants to insert a left child node
		if (s == "y")
		{
			// enter node value for left child node
			cout << "Enter left child node value: ";
			cin >> val;
			
			// create a new node in heap using the user's entered value
			t = new TreeNode(val);
			// set the new node as the left child node of p
			p->left = t;
			// push the new node into the queue
			q.push(t);
		}
		
		// display text and take user input
		cout << "Insert right child node for " << p->val << "? y for yes or n for no: ";
		cin >> s;
		
		// user wants to insert a right child node
		if (s == "y")
		{
			// enter node value for right child node
			cout << "Enter right child node value: ";
			cin >> val;
			
			// create a new node in heap using the user's entered value
			t = new TreeNode(val);
			// set the new node as the right child node of p
			p->right = t;
			// push the new node into the queue
			q.push(t);
		}
	}
	
	// return the root node of the tree
	return root;
}

// extra storage method
// time complexity: O(n) because we only ever loop at most 2n times where 
// n is the number of nodes
// space complexity: O(n) because our containers will use a total of 4n space
// in order to store all the node and null address values
bool isSameTree(TreeNode *p, TreeNode *q)
{
	queue<TreeNode *> pQueue;
	pQueue.push(p);
	// used to store all the node and null address values of p's tree
	vector<TreeNode *> pVector;
	
	// continue until pQueue is empty
	// note that we also store null in the queue
	// which will increase the number of loops to 2n
	// and will give pVector a size of 2n
	while (pQueue.size() != 0)
	{
		TreeNode *p1;
		p1 = pQueue.front();
		pVector.push_back(p1);
		pQueue.pop();
		
		if (p1 != NULL)
		{
			pQueue.push(p1->left);
			pQueue.push(p1->right);
		}
	}
	
	queue<TreeNode *> qQueue;
	qQueue.push(q);
	vector<TreeNode *> qVector;
	
	// continue until qQueue is empty
	// note that we also store null in the queue
	// which will increase the number of loops to 2n
	// and will give qVector a size of 2n
	while (qQueue.size() != 0)
	{
		TreeNode *q1;
		q1 = qQueue.front();
		qVector.push_back(q1);
		qQueue.pop();
		
		if (q1 != NULL)
		{
			qQueue.push(q1->left);
			qQueue.push(q1->right);
		}
	}
	
	for (int i = 0; i < pVector.size(); i++)
	{
		if ((pVector[i] == NULL && qVector[i] != NULL) ||
		(pVector[i] != NULL && qVector[i] == NULL))
		{
			return false;
		}
		else if (pVector[i] != NULL && qVector[i] != NULL)
		{
			if (pVector[i]->val != qVector[i]->val)
			{
				return false;
			}
		}
	}
	
	return true;
}

/*
	Given the roots of two binary trees p and q, write a function to check if 
	they are the same or not. Two binary trees are considered the same if they 
	are structurally identical, and the nodes have the same value.
	
	Constraints:
	The number of nodes in both trees is in the range [0, 100].
	-10^4 <= Node.val <= 10^4
*/
int main()
{
	// set the root node and create the first binary tree
	cout << "First binary tree" << endl;
	TreeNode *root1 = createBinaryTree();
	
	// set the root node and create the second binary tree
	cout << endl << "Second binary tree" << endl;
	TreeNode *root2 = createBinaryTree();
	
	// 1 = true and 0 = false
	cout << isSameTree(root1, root2);
	
	return 0;
}