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

ListNode *reverseList(ListNode *head)
{
	struct ListNode *t1 = NULL;
	struct ListNode *t2 = NULL;
	
	while (head != NULL)
	{
		t2 = t1;
		t1 = head;
		head = head->next;
		
		t1->next = t2;
	}
	
	head = t1;
	
	return head;
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
	head = reverseList(head);
	
	struct ListNode *t = head;
	while (t != NULL)
	{
		cout << t->val << " ";
		
		t = t->next;
	}
	
	return 0;
}