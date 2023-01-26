#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// counter method
// time complexity: O(n) because of the non-nested for loops
// space complexity: O(n) because of the extra vector of size n
int missingNumberCounter(vector<int> nums)
{
	// create a vector that holds 0 to n numbers
	// all elements are initialized to 0
	vector<int> c(nums.size()+1);
	
	// every number that appears in the num vector
	// will be marked in the c vector with a 1
	for (int i = 0; i < nums.size(); i++)
	{
		// using the number as an index for the c vector
		c[nums[i]] = 1;
	}
	
	// will hold the missing number
	int j = 0;
	
	// loop unitl we find the unmarked number
	while (c[i] != 0)
	{
		j++;
	}
	
	return j;
}

// sort method
// time complexity: O(n*log(n)) because of the sort function
// space complexity: O(1) because no extra space of size n is used
int missingNumberSort(vector<int> nums)
{
	// sorts the vector
	sort(nums.begin(), nums.end());
	
	// loop through the vector
	for (int i = 0; i < nums.size(); i++)
	{
		// since the vector is sorted the number
		// should be the same as its index
		if (i != nums[i])
		{
			return i;
		}
	}
	
	// reaching here means that the missing
	// number is n (last number in range and 
	// not part of the nums vector)
	return nums.size();
}

// sum method
// time complexity: O(n) because of the single for loop
// space complexity: O(1) because no extra space of size n is used
int missingNumberSum(vector<int> nums)
{
	// used to get the sum of all the numbers in the vector
	int sum = 0;
	
	// this calculates the sum of 0 to n numbers
	int total = nums.size()*(nums.size()+1)/2;
	
	// adding all the numbers in the vector
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	
	// the missing number will be the difference of
	// the full range added and the nums vector added
	return total - sum;
}

/*
	Given an array nums containing n distinct numbers in the range [0, n], 
	return the only number in the range that is missing from the array.
	
	Constraints:

	n == nums.length
	1 <= n <= 104
	0 <= nums[i] <= n
	All the numbers of nums are unique.
*/
int main()
{
	vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
	
	cout << missingNumberCounter(nums) << endl;
	cout << missingNumberSort(nums) << endl;
	cout << missingNumberSum(nums) << endl;
	
	return 0;
}