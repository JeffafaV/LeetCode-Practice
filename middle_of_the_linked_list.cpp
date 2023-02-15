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

// count nodes method
// time complexity: O(n) because we loop through the full list once and 
// then we go through it again up to the middle node
// space complexity: O(1) because we use the same amount of variables 
// of the same size regardless of what n is
ListNode *middleNodeCount(ListNode *head)
{
	// used to traverse the list
	ListNode *t1 = head;
	
	// counts the number of nodes
	int nodeCount = 1;
	
	// go through entire list and increment nodeCount
	while (t1->next != NULL)
	{
		t1 = t1->next;
		nodeCount++;
	}
	
	// divide node count by 2 to get the middle node position
	int middlePos = nodeCount/2;
	
	// used to reach the middle node
	// we can also reuse t1
	ListNode *t2 = head;
	
	// travese linked list until we reach the middle node
	for (int i = 0; i < middlePos; i++)
	{
		t2 = t2->next;
	}
	
	return t2;
}

// fast and slow pointer method
// time complexity: O(n) because we only loop through half way of the list
// space complexity: O(1) because we only need two extra pointers regardless of n
ListNode *middleNodeFS(ListNode *head)
{
	// fast pointer
	ListNode *t1 = head;
	// slow pointer
	ListNode *t2 = head;
	
	// loop until either t1 is null or next points to null
	while (t1 != NULL && t1->next != NULL)
	{
		// increment by 1 node
		t2 = t2->next;
		// increment by 2 nodes
		t1 = t1->next->next;
	}
	
	// since t1 is incrementing by two nodes and t2 is incrementing by one
	// when t1 reaches the end of the list t2 will be at the middle of the list
	return t2;
}

/*
	Given the head of a singly linked list, return the middle node of the linked list.
	If there are two middle nodes, return the second middle node.
	
	Constraints:
	The number of nodes in the list is in the range [1, 100].
	1 <= Node.val <= 100
*/
int main()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	
	ListNode *head = createLinkedList(nums);
	ListNode *middle = middleNodeCount(head);
	ListNode *t = middle;
	
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	
	cout << endl;
	
	ListNode *head2 = createLinkedList(nums);
	ListNode *middle2 = middleNodeCount(head2);
	ListNode *t2 = middle2;
	
	while (t2 != NULL)
	{
		cout << t2->val << " ";
		t2 = t2->next;
	}
	
	
	return 0;
}