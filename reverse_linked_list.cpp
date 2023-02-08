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

// pointer method
// time complexity: O(n) because we are looping through the whole linked list
// space complexity: O(1) because we only use two extra pointers
ListNode *reverseListPointer(ListNode *head)
{
	struct ListNode *t1 = NULL; // behind head
	struct ListNode *t2 = NULL; // behind t1
	
	// keep looping until head reaches null
	while (head != NULL)
	{
		// move t2 to t1's position
		t2 = t1;
		// move t1 to head's position
		t1 = head;
		// move head to the next node
		head = head->next;
		
		// have t1 point to t2 which will reverse a link
		// this is done for all the links
		t1->next = t2;
	}
	
	// head is at null so we have to set head to t1 which 
	// is the first node or you can just return t1
	head = t1;
	
	return head;
}

// recursive method
// time complexity: O(n) because the function is called n times
// space complexity: O(n) because of the recursive calls stacking
ListNode *reverseListRecursive(ListNode *head)
{
	// basically used to get the last node which
	// will become the head node
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	
	// gets the new head node
	// the recursive calls don't change this value
	ListNode *new_head = reverseListRecursive(head->next);
	
	// we're at a current node
	// what this does is changes the next pointer of the node that is ahead 
	// of the current node and makes it point to the current node which reverses it
	head->next->next = head;
	// the current node points to null
	head->next = NULL;
	
	return new_head;
}

/*
	Given the head of a singly linked list, reverse the list, and return the reversed list.
	
	Constraints:
	The number of nodes in the list is the range [0, 5000].
	-5000 <= Node.val <= 5000
*/
int main()
{
	vector<int> nums = {3, 2, 0, -4};
	
	ListNode *head = createLinkedList(nums);
	head = reverseListPointer(head);
	
	struct ListNode *t = head;
	while (t != NULL)
	{
		cout << t->val << " ";
		
		t = t->next;
	}
	cout << endl;
	
	ListNode *head2 = createLinkedList(nums);
	head2 = reverseListRecursive(head2);
	
	t = head2;
	
	while (t != NULL)
	{
		cout << t->val << " ";
		
		t = t->next;
	}
	cout << endl;
	
	return 0;
}