#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBinaryTree()
{
	TreeNode *root = NULL;
	queue<TreeNode *> q;
	string s;
	cout << "Insert root node? y for yes or n for no: ";
	cin >> s;
	
	if (s == "n")
	{
		return NULL;
	}
	
	int val;
	cout << "Enter root node value: ";
	cin >> val;
	
	root = new TreeNode(val);
	q.push(root);
	
	while (q.size() != 0)
	{
		TreeNode *t = NULL;
		TreeNode *p = q.front();
		q.pop();
		
		cout << "Insert left child node for " << p->val << "? y for yes or n for no: ";
		cin >> s;
		
		if (s == "y")
		{
			cout << "Enter left child node value: ";
			cin >> val;
			
			t = new TreeNode(val);
			p->left = t;
			q.push(t);
		}
		
		cout << "Insert right child node for " << p->val << "? y for yes or n for no: ";
		cin >> s;
		
		if (s == "y")
		{
			cout << "Enter right child node value: ";
			cin >> val;
			
			t = new TreeNode(val);
			p->right = t;
			q.push(t);
		}
	}
	
	return root;
}

// this a function
bool isSameTree(TreeNode *p, TreeNode *q)
{
	queue<TreeNode *> pQueue;
	pQueue.push(p);
	vector<TreeNode *> pVector;
	
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

int main()
{
	cout << "First binary tree" << endl;
	TreeNode *root1 = createBinaryTree();
	
	cout << endl << "Second binary tree" << endl;
	TreeNode *root2 = createBinaryTree();
	
	// 1 = true and 0 = false
	cout << isSameTree(root1, root2);
	
	return 0;
}