#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList
{
	private:
	struct ListNode *head;
	struct ListNode *tail;
	
	public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	
	LinkedList(vector<int> nums)
	{
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
	}
	
	bool hasCycle();
};

bool LinkedList::hasCycle()
{
	struct ListNode *t1 = head;
	struct ListNode *t2 = head;
	
	while (t2 != NULL)
	{
		t1 = t1->next;
		t2 = t2->next;
		
		if (t2 != NULL)
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


int main()
{
	vector<int> nums = {3, 2, 0, -4};
	LinkedList l(nums);
	
	cout << l.hasCycle() << endl;
}