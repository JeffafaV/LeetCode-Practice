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

// fast and slow pointer method
// time complexity: O(n) because the while loop iterates n times
// if the last node loops to the first node
// space complexity: O(1) because no extra space of size n is used
ListNode* detectCycle(ListNode *head)
{
	// moves by one
	struct ListNode *slow = head;
	// moves by two
	struct ListNode *fast = head;
	
	// this is for special cases when there are 0 nodes
	// or just 1 node with no loop
	if (slow == NULL || slow->next == NULL)
	{
		return NULL;
	}
	
	// move to the next node if fast's current node isn't null
	// and if the next node from fast's current node isn't null
	// we don't have to check slow since it is behind fast
	while (fast != NULL && fast->next != NULL)
	{
		// move slow one node
		slow = slow->next;
		// move fast two nodes
		fast = fast->next->next;
		
		// there is a loop if fast ends up at the same node as slow
		if (slow == fast)
		{
			break;
		}
	}
	
	// there is no loop
	if (slow != fast)
	{
		return NULL;
	}
	
	// move slow to the front of the list
	slow = head;
	
	// moving slow and fast by one node will have both pointers
	// reach the same node which will be the first node of the loop
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow;
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

void getPos(ListNode *head, ListNode *node)
{
	int count = 0;
	
	if (node == NULL)
	{
		cout << "no cycle";
		
		return;
	}
	
	ListNode *t = head;
	
	while (t != node)
	{
		count++;
		t = t->next;
	}
	
	cout << "tail connects to node index " << count;
}

/*
	Given the head of a linked list, return the node where the cycle begins. If there 
	is no cycle, return null. There is a cycle in a linked list if there is some node 
	in the list that can be reached again by continuously following the next pointer. 
	Internally, pos is used to denote the index of the node that tail's next pointer 
	is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not 
	passed as a parameter. Do not modify the linked list.
	
	Constraints:
	The number of the nodes in the list is in the range [0, 10^4].
	-10^5 <= Node.val <= 10^5
	pos is -1 or a valid index in the linked-list.
*/
int main()
{
	vector<int> nums = {3, 2, 0, -4};
	
	struct ListNode *head = createLinkedList(nums);
	addLoop(head, -1, nums.size());
	struct ListNode *firstInCycle = detectCycle(head);
	
	getPos(head, firstInCycle);
	
	return 0;
}