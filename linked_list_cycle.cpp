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
// fast and slow pointer method 1
// time complexity: O(n) because the while loop iterates n times
// if the last node loops to the first node
// space complexity: O(1) because no extra space of size n is used
bool hasCycleFS1(ListNode *head)
{
	// slow pointer
	struct ListNode *t1 = head;
	// fast pointer
	struct ListNode *t2 = head;
	
	// move to the next node if t2's current node isn't null
	while (t2 != NULL)
	{
		// move to the next node
		t1 = t1->next;
		t2 = t2->next;
		
		// check if the current t2 node isn't null
		if ( t2 != NULL)
		{
			// only move t2 to the next node
			t2 = t2->next;
		}
		
		// since t2 is going twice as fast as t1, t2 will reach t1 if there is a loop
		// except for the case in which there is a linked list with one node
		// without a loop in which case we have to make sure t1 and t2 aren't null
		if (t1 == t2 && t1 != NULL && t2 != NULL)
		{
			return true;
		}
	}
	
	return false;
}

// fast and slow pointer method 2
// time complexity: O(n) because the while loop iterates n times
// if the last node loops to the first node
// space complexity: O(1) because no extra space of size n is used
bool hasCycleFS2(ListNode *head)
{
	// slow pointer
	struct ListNode *t1 = head;
	// fast pointer
	struct ListNode *t2 = head;
	
	// move to the next node if t2's current node isn't null
	// and if the next node from t2's current node isn't null
	// we don't have to check t1 since it is behind t2
	while (t2 != NULL && t2->next != NULL)
	{
		// move t1 one node
		t1 = t1->next;
		// move t2 two nodes
		t2 = t2->next->next;
		
		// since t2 is going twice as fast as t1, t2 will reach t1 if there is a loop
		if (t1 == t2)
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
	
	struct ListNode *head = createLinkedList(nums);
	addLoop(head, -1, nums.size());
	
	// 1 = true and 0 = false
	cout << hasCycleFS1(head) << endl;
	cout << hasCycleFS2(head) << endl;
	
	return 0;
}