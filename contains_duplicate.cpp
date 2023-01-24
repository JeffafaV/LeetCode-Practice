#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

// sort method
// time complexity: O(n*log(n)) because of the sort function
// space complexity: O(1) because no extra space of size n is used
bool containsDuplicateSort(vector<int> nums)
{
	// sort the vector
	sort(nums.begin(), nums.end());
	
	// if the next element is the same as the current
	// then it means there is a duplicate
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] == nums[i+1])
		{
			return true;
		}
	}
	
	return false;
}

// set method
// time complexity: O(n*log(n)) because set insertion is log(n) and
// we're doing it n times
// space complexity: O(n) because the set can be of size n
bool containsDuplicateSet(vector<int> nums)
{
	// inserting the elements in nums in a set
	// which removes any duplicates
	set<int> s(nums.begin(), nums.end());
	
	// the set is smaller than the vector
	// meaning there were duplicates
	if (s.size() < nums.size())
	{
		return true;
	}
	
	return false;
}

// unordered set method
// time complexity: O(n) because unordered_set insertion is constant and
// we're doing it n times
// space complexity: O(n) because the unordered set can be of size n
bool containsDuplicateUnorderedSet(vector<int> nums)
{
	// inserting the elements in nums in a set
	// which removes any duplicates
	unordered_set<int> s(nums.begin(), nums.end());
	
	// the set is smaller than the vector
	// meaning there were duplicates
	if (s.size() < nums.size())
	{
		return true;
	}
	
	return false;
}

/*
	Given an integer array nums, return true if any value appears at least twice 
	in the array, and return false if every element is distinct.
	
	Constraints:
	1 <= nums.length <= 10^5
	-10^9 <= nums[i] <= 10^9
*/
int main()
{
	vector<int> nums = {1, 2, 3, 4};
	
	// 1 = true and 0 = false
	cout << containsDuplicateSort(nums) << endl;
	cout << containsDuplicateSet(nums) << endl;
	cout << containsDuplicateUnorderedSet(nums) << endl;
	
	return 0;
}