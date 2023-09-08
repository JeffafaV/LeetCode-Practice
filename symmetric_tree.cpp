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
// time complexity: O(n) because we only ever loop at most n times in each loop and 
// n is the number of nodes for the tree
// space complexity: O(n) because our containers will use a total of 2n space
// in order to store all the node and null address values
bool isSymmetric(TreeNode *root)
{
	// queue used to hold the left side of the tree's TreeNode pointers
	// used to help go through the tree in level order
	queue<TreeNode *> lQueue;
	// push root's left address value into the queue
	lQueue.push(root->left);
	// used to store all the node and null address values of the left side of the tree
	vector<TreeNode *> lVector;
	
	// continue until lQueue is empty
	// note that we also store null in the queue
	// which will increase the number of loops to n
	// and will give lVector a size of n
	while (lQueue.size() != 0)
	{
		// used to hold the first item in the queue
		TreeNode *lt;
		// set lt to the first item in the queue which can be a node or null address
		lt = lQueue.front();
		// push lt's value (node address or null) into the vector
		lVector.push_back(lt);
		// remove the first item from the queue
		lQueue.pop();
		
		// lt points to a node
		if (lt != NULL)
		{
			// push lt's left child to the queue
			lQueue.push(lt->left);
			// push lt's right child to the queue
			lQueue.push(lt->right);
		}
	}
	
	// queue used to hold the right side of the tree's TreeNode pointers
	// used to help go through the tree in level order
	queue<TreeNode *> rQueue;
	// push root's right address value into the queue
	rQueue.push(root->right);
	// used to store all the node and null address values of the right side of the tree
	vector<TreeNode *> rVector;
	
	// continue until rQueue is empty
	// note that we also store null in the queue
	// which will increase the number of loops to n
	// and will give rVector a size of n
	while (rQueue.size() != 0)
	{
		// used to hold the first item in the queue
		TreeNode *rt;
		// set rt to the first item in the queue which can be a node or null address
		rt = rQueue.front();
		// push rt's value (node address or null) into the vector
		rVector.push_back(rt);
		// remove the first item from the queue
		rQueue.pop();
		
		// rt points to a node
		if (rt != NULL)
		{
			// push rt's right child to the queue
			rQueue.push(rt->right);
			// push rt's left child to the queue
			rQueue.push(rt->left);
			
			// note that since we are checking if the left and right side are mirrored
			// we have to first push rt's right child, this way the nodes in the vectors are
			// aligned correctly and we can then check if the structure and values are the same
		}
	}
	
	// loop through all pointer values in both sides using their vectors
	// note that both sides have the same number of nodes (n/2 nodes) 
	// and we can use either lVector.size() or rVector.size()
	for (int i = 0; i < lVector.size(); i++)
	{
		// current item in one side is null and the 
		// current item in the other side is a node
		if ((lVector[i] == NULL && rVector[i] != NULL) ||
		(lVector[i] != NULL && rVector[i] == NULL))
		{
			// reaching here means that the sides don't have the 
			// same structure so we return false
			return false;
		}
		// current item in both sides are nodes
		else if (lVector[i] != NULL && rVector[i] != NULL)
		{
			// current node values are not the same
			if (lVector[i]->val != rVector[i]->val)
			{
				// reaching here means that the sides don't have the 
				// same values in their nodes so we return false
				return false;
			}
		}
	}
	
	// reaching here means that the sides are mirrored 
	// (symmetrically identical) and have the same node values
	return true;
}

/*
	Given the root of a binary tree, check whether it is a mirror of itself 
	(i.e., symmetric around its center).
	
	Constraints:
	The number of nodes in the tree is in the range [1, 1000].
	-100 <= Node.val <= 100
*/
int main()
{
	// set the root node and create the binary tree
	cout << "First binary tree" << endl;
	TreeNode *root = createBinaryTree();
	
	// 1 = true and 0 = false
	cout << isSymmetric(root);
	
	return 0;
}