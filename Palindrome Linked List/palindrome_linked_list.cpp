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
// time complexity: O(n) since we only travese half of the list three times
// space complexity: O(1) since we only need to create a few ListNode pointers 
// regardless of n
bool isPalindrome(ListNode* head) {
	// fast pointer moves two nodes at a time
	ListNode *fast = head;
	// slow pointer moves one node at a time
	ListNode *slow = head;

	// traverse the linked list until fast reaches null or the last node
	while (fast != nullptr && fast->next != nullptr)
	{
		// move slow by one node
		slow = slow->next;
		// move fast by two nodes
		fast = fast->next->next;
	}

	// prev node will be one node behind current
	ListNode *prev = nullptr; // is initialized to null at first
	// is the current node while traversing the linked list
	ListNode *current = slow; // is initialized to slow which is the middle node

	/*
		The main idea here is that we want to reverse and split the second half of the 
		linked list. So, starting at slow, which is the middle node, we reverse and split 
		the remaining second half.
		Ex. A->B->C->B->A will be A->B->
	                                    C
								  A->B->
		
		Ex. A->B->B->A will be A->B->
		                             B
								  A->
		The two linked list meet at the middle node. Now you can traverse both splits 
		to see if it is a palindrome.
	*/

	// traverse the second half of the linked list until it reaches the end
	while (current != nullptr)
	{
		// create a next pointer that points to the node ahead of current
		ListNode *next = current->next;
		// set the next pointer of the current node to point to the previous node
		current->next = prev;
		// move prev up one node to current
		prev = current;
		// move current up one node to next
		current = next;
	}

	// left pointer is set to the head of the original linked list
	ListNode *left = head;
	// right pointer is set to the first node of the reversed linked list
	ListNode *right = prev;

	// traverse the two splits until right reaches null
	// note: we check if right is null instead of left because it reaches null first
	while (right != nullptr)
	{
		// check if the value of the left and right node are not the same
		if (left->val != right->val)
		{
			// not a palindrome
			return false;
		}

		// move up one node for both splits
		left = left->next;
		right = right->next;
	}

	// is a palindrome
	return true;
}

/*
	Given the head of a singly linked list, return true if it is a palindrome or 
	false otherwise.
	
	Constraints:
	The number of nodes in the list is in the range [1, 10^5].
	0 <= Node.val <= 9
*/
int main()
{
	vector<int> nums = {1, 2, 2, 1};

	struct ListNode *head = createLinkedList(nums);

	// 1 = true, 0 = false
	cout << isPalindrome(head);
}