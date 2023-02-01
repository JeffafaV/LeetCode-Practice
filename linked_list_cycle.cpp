#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(vector<int> nums)
{
	struct ListNode *head = NULL;
	struct ListNode *tail = NULL;
	struct ListNode *t = NULL;
	
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
	
	struct ListNode *t3 = head;
	struct ListNode *t4 = head;
	
	/*
	while (t3->next != NULL)
	{
		t3 = t3->next;
	}
	
	t3->next = t4;
	*/
	
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

void addLoop(ListNode *head, int pos, int size)
{
	if (pos >= 0 && pos < size)
	{
		struct ListNode *t1 = head;
		struct ListNode *t2 = head;
		
		while (t1->next != NULL)
		{
			t1 = t1->next;
		}
		
		for (int i = 0; i < pos; i++)
		{
			t2 = t2->next;
		}
		
		t1->next = t2;
	}
}

int main()
{
	vector<int> nums = {3, 2, 0, -4};
	ListNode *head = createLinkedList(nums);
	addLoop(head, -1, nums.size());
	cout << hasCycle(head) << endl;
}