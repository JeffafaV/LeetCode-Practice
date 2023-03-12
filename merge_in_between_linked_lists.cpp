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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
	ListNode *mergeEnd = list1;
	for (int i = 0; i <= b; i++)
	{
		mergeEnd = mergeEnd->next;
	}
	
	ListNode *mergeStart = list1;
	for (int i = 0; i < a-1; i++)
	{
		mergeStart = mergeStart->next;
	}
	
	// extra step to delete the nodes that will be removed
	// this is not necessary for the merge
	ListNode *t1 = mergeStart->next;
	ListNode *t2 = NULL;
	for (int i = 0; i <= b-a; i++)
	{
		t2 = t1;
		t1 = t1->next;
		delete t2;
	}
	
	mergeStart->next = list2;
	
	ListNode *list2End = list2;
	while (list2End->next != NULL)
	{
		list2End = list2End->next;
	}
	
	list2End->next = mergeEnd;
	
	return list1;
}

/*
	You are given two linked lists: list1 and list2 of sizes n and m 
	respectively. Remove list1's nodes from the ath node to the bth 
	node, and put list2 in their place.
	
	Constraints:
	3 <= list1.length <= 10^4
	1 <= a <= b < list1.length - 1
	1 <= list2.length <= 10^4
*/
int main()
{
	vector<int> nums1 = {0, 1, 2, 3, 4, 5};
	vector<int> nums2 = {1000000, 1000001, 1000002};
	
	struct ListNode *head1 = createLinkedList(nums1);
	struct ListNode *head2 = createLinkedList(nums2);
	
	int a = 3;
	int b = 4;
	
	head1 = mergeInBetween(head1, a, b, head2);
	
	struct ListNode *t = head1;
	
	while (t != NULL)
	{
		cout << t->val << " ";
		t = t->next;
	}
	
	return 0;
}