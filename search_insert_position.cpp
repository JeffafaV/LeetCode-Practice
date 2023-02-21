#include <iostream>
#include <vector>

using namespace std;

// binary search method
// time complexity: O(log(n)) because we are using binary search
// space complexity: O(1) because we only use three int variables
int searchInsert(vector<int> nums, int target)
{
	// left end pointer
	int low = 0;
	// right end pointer
	int high = nums.size()-1;
	// middle pointer
	int mid;
	
	// continue looping until the right and left pointers 
	// cross each other
	while (low <= high)
	{
		// calculate the index of middle pointer
		// alternatively we can use low + (high - low) / 2
		// however given the restraints this is fine
		mid = (low + high) / 2;
		
		// the target was found
		if (nums[mid] == target)
		{
			return mid;
		}
		
		// the middle index is less than target, that means we have to 
		// move the low pointer to mid+1 to get closer to the target
		if (nums[mid] < target)
		{
			low = mid + 1;
		}
		// the middle index is greater than target, that means we have to 
		// move the high pointer to mid-1 to get closer to the target
		else
		{
			high = mid - 1;
		}
	}
	
	// the low pointer will end up reaching the index in which the 
	// target should be in if it is not present in the array
	return low;
}

/*
	Given a sorted array of distinct integers and a target value, return 
	the index if the target is found. If not, return the index where it 
	would be if it were inserted in order.
	You must write an algorithm with O(log n) runtime complexity.
	
	Constraints:
	1 <= nums.length <= 10^4
	-10^4 <= nums[i] <= 10^4
	nums contains distinct values sorted in ascending order.
	-10^4 <= target <= 10^4
*/
int main()
{
	vector<int> nums = {1, 3, 5, 6};
	int target = 2;
	
	int index = searchInsert(nums, target);
	
	cout << index;
	
	return 0;
}