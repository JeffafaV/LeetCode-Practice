#include <iostream>
#include <vector>

using namespace std;

// binary search method
// time complexity: O(log(n)) because it halves the array in each iteration
// space complexity: O(1) because we only need 3 int variables
int search(vector<int> nums, int target)
{
	// index pointers
	int left = 0;
	int right = nums.size()-1;
	int mid;
	
	// continue until they cross
	while (left <= right)
	{
		// get the middle index
		mid = left + (right - left) / 2;
		
		// return index if target matches the 
		// element of the mid index
		if (nums[mid] == target)
		{
			return mid;
		}
		// if the element of the mid index 
		// is greater than the target then
		// move the right pointer behind mid
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		// if the element of the mid index 
		// is less than the target then
		// move the left pointer ahead mid
		else
		{
			left = mid + 1;
		}
	}
	
	// reaching here means the target is not in the vector
	return -1;
}

/*
	Given an array of integers nums which is sorted in ascending order, and 
	an integer target, write a function to search target in nums. If target 
	exists, then return its index. Otherwise, return -1.
	You must write an algorithm with O(log n) runtime complexity.
	
	Constraints:
	1 <= nums.length <= 10^4
	-10^4 < nums[i], target < 10^4
	All the integers in nums are unique.
	nums is sorted in ascending order.
*/
int main()
{
	vector<int> nums = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	
	cout << search(nums, target) << endl;
	
	return 0;
}