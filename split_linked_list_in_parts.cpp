#include <iostream>
#include <vector>

using namespace std;

// structure that holds individual nodes
struct ListNode
{
	int val;
	ListNode *next;
	
	// parameterized constructor
	ListNode(int x) : val(x), next(NULL) {}
};

// creates a linked list using the terms in the vector
ListNode *createLinkedList(vector<int> nums)
{
	struct ListNode *head = NULL;
	struct ListNode *tail = NULL;
	struct ListNode *t = NULL;
	
	// creates a new node in heap for every term in the vector
	for (int i = 0; i < nums.size(); i++)
	{
		t = new struct ListNode(nums[i]);
		
		if (head == NULL)
		{
			head = t;
			tail = t;
		}
		else
		{
			tail->next = t;
			tail = t;
		}
	}
	
	return head;
}

// node counter method
// time complexity:
// space complexity:
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
	ListNode *t = head;
	ListNode *s = NULL;
	vector<ListNode *> v;
	
	int nodeCount = 0;
	while (t != NULL)
	{
		nodeCount++;
		t = t->next;
	}
	
	int nodesPerPart = nodeCount / k;
	int partsWithExtraNode = nodeCount % k;
	int currentNode = 0;
	int extraNodeCounter = 0;
	
	t = head;
	
	if (t != NULL)
	{
		v.push_back(t);
	}
	
	while (t != NULL)
	{
		if (extraNodeCounter < partsWithExtraNode)
		{
			if (currentNode == (nodesPerPart+1))
			{
				v.push_back(t);
				s->next = NULL;
				extraNodeCounter++;
				currentNode = 0;
			}
		}
		
		else
		{
			if (currentNode == nodesPerPart)
			{
				v.push_back(t);
				s->next = NULL;
				currentNode = 0;
			}
		}
		
		s = t;
		t = t->next;
		currentNode++;
	}
	
	if (k > nodeCount)
	{
		for (int i = 0; i < k - nodeCount; i++)
		{
			v.push_back(NULL);
		}
	}
	
	return v;
}

/*
	Given the head of a singly linked list and an integer k, split the linked list into 
	k consecutive linked list parts. The length of each part should be as equal as 
	possible: no two parts should have a size differing by more than one. This may 
	lead to some parts being null. The parts should be in the order of occurrence in 
	the input list, and parts occurring earlier should always have a size greater than 
	or equal to parts occurring later. Return an array of the k parts.
	
	Constraints:
	The number of nodes in the list is in the range [0, 1000].
	0 <= Node.val <= 1000
	1 <= k <= 50
*/
int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<ListNode *> parts;
	int k = 3;
	
	ListNode *head = createLinkedList(nums);
	parts = splitListToParts(head, k);
	
	ListNode *t = NULL;
	cout << "[";
	for (int i = 0; i < parts.size(); i++)
	{
		t = parts[i];
		cout << "[";
		
		while (t != NULL)
		{
			if (t->next != NULL)
			{
				cout << t->val << ",";
			}
			else
			{
				cout << t->val;
			}
			
			t = t->next;
		}
		
		if (i != parts.size()-1)
		{
			cout << "],";
		}
		else
		{
			cout << "]";
		}
	}
	
	cout << "]";
	
	return 0;
}