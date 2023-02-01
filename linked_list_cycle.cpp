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

bool hasCycle(ListNode *head)
{
	struct ListNode *t1 = head;
	struct ListNode *t2 = head;
	
	while (t2 != NULL)
	{
		t1 = t1->next;
		t2 = t2->next;
		
		if ( t2 != NULL)
		{
			t2 = t2->next;
		}
		
		if (t1 == t2 && t1 != NULL && t2 != NULL)
		{
			return true;
		}
	}
	
	return false;
}

// used to add a loop depending on pos
void addLoop(ListNode *head, int pos, int size)
{
	// make sure pos is valid in order to add loop
	// if not then no loop is added
	if (pos >= 0 && pos < size)
	{
		struct ListNode *t1 = head;
		struct ListNode *t2 = head;
		
		// move t1 to the last node
		while (t1->next != NULL)
		{
			t1 = t1->next;
		}
		
		// move t2 to pos position node
		for (int i = 0; i < pos; i++)
		{
			t2 = t2->next;
		}
		
		// last node loops to pos node
		t1->next = t2;
	}
}

/*
	Given head, the head of a linked list, determine if the linked list has a cycle in it.
	There is a cycle in a linked list if there is some node in the list that can be reached again 
	by continuously following the next pointer. Internally, pos is used to denote the index of the 
	node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
	Return true if there is a cycle in the linked list. Otherwise, return false.
	
	Constraints:
	The number of the nodes in the list is in the range [0, 104].
	-105 <= Node.val <= 105
	pos is -1 or a valid index in the linked-list.
*/
int main()
{
	vector<int> nums = {3, 2, 0, -4};
	
	ListNode *head = createLinkedList(nums);
	addLoop(head, -1, nums.size());
	
	cout << hasCycle(head) << endl;
	
	return 0;
}