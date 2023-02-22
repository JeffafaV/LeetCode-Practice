#include <iostream>
#include <vector>

using namespace std;

// tabulation method
// time complexity: O(n) because we loop through a vector of size n
// space complexity: O(n) because we create a vector of size n
int climbStairs(int n)
{
	// each entry is the number of ways you can climb up for that number of steps (index)
	// the size is n+1 because the range is [0, n]
	vector<int> ways(n+1);
	
	// for 0 steps we are inserting a default value of 1
	ways[0] = 1;
	// for 1 step there is only one way to climb up
	ways[1] = 1;
	
	// loop through the rest of the vector
	for (int i = 2; i < ways.size(); i++)
	{
		// to get the number of ways for the current index 
		// we have to add the values of the previous two values
		ways[i] = ways[i-1] + ways[i-2];
	}
	
	return ways[n];
}

/*
	You are climbing a staircase. It takes n steps to reach the top.

	Each time you can either climb 1 or 2 steps. In how many distinct 
	ways can you climb to the top?
	
	Constraints:
	1 <= n <= 45
*/
int main()
{
	int steps = 5;
	int ways = climbStairs(steps);
	
	cout << ways;
	
	return 0;
}