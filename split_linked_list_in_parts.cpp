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
// time complexity: O(n) because we only ever loop at most n times except 
// for when k is bigger than n in which case it is O(k)
// space complexity: O(k) because we will have a vector that holds k values
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
	// used to traverse the linked list
	ListNode *t = head;
	// this pointer will be one node behind t
	ListNode *s = NULL;
	// will hold the first pointer of each part
	vector<ListNode *> v;
	
	// used to count the number of nodes in the linked list
	int nodeCount = 0;
	
	// loop through entire linked list
	while (t != NULL)
	{
		// increment node counter
		nodeCount++;
		// move t to the next node in the linked list
		t = t->next;
	}
	
	// calculate how many nodes will be in each part
	int nodesPerPart = nodeCount / k;
	// calculate how many parts will have an extra node
	int partsWithExtraNode = nodeCount % k;
	// an index counter to see what node we are on when looping
	int currentNode = 0;
	// a counter to see if the current part will need an extra node or not
	int extraNodeCounter = 0;
	
	// set t to head so that we can traverse the linked list again
	t = head;
	
	// t is a node
	if (t != NULL)
	{
		// push the first node of the first part into the vector
		v.push_back(t);
	}
	
	// loop through the entire linked list
	while (t != NULL)
	{
		// current part will have an extra node
		if (extraNodeCounter < partsWithExtraNode)
		{
			// pointer t reached the first node of the next part
			if (currentNode == (nodesPerPart+1))
			{
				// push t into the vector which is the first node of the next part
				v.push_back(t);
				// s is pointing to the last node of the current part
				// and we set its next pointer to null to separate the parts
				s->next = NULL;
				// increment the parts with an extra node counter
				extraNodeCounter++;
				// reset the current node counter to 0 since that is the 
				// index of the first node of the new part
				currentNode = 0;
			}
		}
		// current part will not have an extra node
		else
		{
			// pointer t reached the first node of the next part
			if (currentNode == nodesPerPart)
			{
				// push t into the vector which is the first node of the next part
				v.push_back(t);
				// s is pointing to the last node of the current part
				// and we set its next pointer to null to separate the parts
				s->next = NULL;
				// reset the current node counter to 0 since that is the 
				// index of the first node of the new part
				currentNode = 0;
			}
		}
		
		// have s point to t
		s = t;
		// have t point to the next node
		t = t->next;
		// increment the index counter
		currentNode++;
	}
	
	// k is bigger than the amount of nodes in the linked list
	if (k > nodeCount)
	{
		// loop through k - nodeCount times to fill in the rest of the vector 
		for (int i = 0; i < k - nodeCount; i++)
		{
			// since k is bigger than nodeCount we would need to insert 
			// null values into the vector in order to get k parts 
			v.push_back(NULL);
		}
	}
	
	// return the vector
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
	// array of numbers that will be used for the linked list
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// vector to hold all the first nodes of each part
	vector<ListNode *> parts;
	// number of parts
	int k = 3;
	
	// set head to be the first node of the created linked list
	ListNode *head = createLinkedList(nums);
	// set the vector to the output of the function
	parts = splitListToParts(head, k);
	
	// pointer used to traverse each part
	ListNode *t = NULL;
	
	cout << "[";
	
	// loop through all the head nodes in the vector
	for (int i = 0; i < parts.size(); i++)
	{
		// set t to the current head node
		t = parts[i];
		
		cout << "[";
		
		// loop through the entire current part
		while (t != NULL)
		{
			// print current node in a part
			if (t->next != NULL)
			{
				cout << t->val << ",";
			}
			else
			{
				cout << t->val;
			}
			
			// move t to the next node in the part
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