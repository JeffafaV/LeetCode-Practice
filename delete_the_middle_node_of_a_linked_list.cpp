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
ListNode *deleteMiddleCount(ListNode *head)
{
	// this is a special case for when the list has only one node
	if (head->next == NULL)
	{
		delete head;
		
		return NULL;
	}
	
	// used to traverse the list to count the number of nodes
	ListNode *temp = head;
	// used to get to the middle node
	ListNode *t1 = head;
	// this will be behind t1
	ListNode *t2 = NULL;
	
	// counts the number of nodes
	int nodeCount = 1;
	
	// go through entire list and increment nodeCount
	while (temp->next != NULL)
	{
		temp = temp->next;
		nodeCount++;
	}
	
	// divide node count by 2 to get the middle node position
	int middlePos = nodeCount/2;
	
	// travese linked list until we reach the middle node
	for (int i = 0; i < middlePos; i++)
	{
		t2 = t1;
		t1 = t1->next;
	}
	
	// have t2 point to whatever the middle node is pointing to
	// this is necessary so that the linked list doesn't break
	t2->next = t1->next;
	// delete the middle node
	delete t1;
	
	return head;
}

// fast and slow pointer method
// time complexity: O(n) because we only loop through half way of the list
// space complexity: O(1) because we only need three extra pointers regardless of n
ListNode *deleteMiddleFS(ListNode *head)
{
	// this is a special case for when the list has only one node
	if (head->next == NULL)
	{
		delete head;
		
		return NULL;
	}
	
	// fast pointer
	ListNode *t1 = head;
	// slow pointer
	ListNode *t2 = head;
	// behind t2 by 1 node
	ListNode *t3 = NULL;
	
	// loop until either t1 is null or next points to null
	while (t1 != NULL && t1->next != NULL)
	{
		// move up to t2
		t3 = t2;
		// increment by 1 node
		t2 = t2->next;
		// increment by 2 nodes
		t1 = t1->next->next;
	}
	
	// have t3 point to whatever the middle node is pointing to
	// this is necessary so that the linked list doesn't break
	t3->next = t2->next;
	// delete the middle node
	delete t2;
	
	return head;
}

/*
	You are given the head of a linked list. Delete the middle node, and return the head of the 
	modified linked list. 
	
	The middle node of a linked list of size n is the [n / 2]th node from 
	the start using 0-based indexing, where [x] denotes the largest integer less than or equal to x.
	
	For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
	
	Constraints:
	The number of nodes in the list is in the range [1, 10^5].
	1 <= Node.val <= 10^5
*/
int main()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	
	ListNode *head = createLinkedList(nums);
	head = deleteMiddleCount(head);
	ListNode *t = head;
	
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	
	cout << endl;
	
	ListNode *head2 = createLinkedList(nums);
	head2 = deleteMiddleFS(head2);
	ListNode *t2 = head2;
	
	while (t2 != NULL)
	{
		cout << t2->val << " ";
		t2 = t2->next;
	}
	
	
	return 0;
}