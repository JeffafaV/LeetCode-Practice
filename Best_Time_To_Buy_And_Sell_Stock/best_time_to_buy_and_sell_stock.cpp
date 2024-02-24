#include <iostream>
#include <vector>

using namespace std;

// tabulation method
// time complexity: O(n) because the for loop iterates n times
// space complexity: O(1) because we have a constant number of variables
int maxProfit(vector<int> prices)
{
	// will hold the max profit
	int maxProf = 0;
	// will hold the smallest price/number in the vector
	int smallestPrice = prices[0];
	
	// loop through the vector
	for (int i = 1; i < prices.size(); i++)
	{
		// the current price is smaller than smallestPrice
		if (smallestPrice > prices[i])
		{
			// change smallestPrice to the current price
			smallestPrice = prices[i];
		}
		
		// maxProf is smaller than the current profit
		if (maxProf < prices[i] - smallestPrice)
		{
			// change maxProf to the current profit
			maxProf = prices[i] - smallestPrice;
		}
	}
	
	return maxProf;
}

/*
	You are given an array prices where prices[i] is the price of a given 
	stock on the ith day. You want to maximize your profit by choosing a 
	single day to buy one stock and choosing a different day in the future 
	to sell that stock. Return the maximum profit you can achieve from this 
	transaction. If you cannot achieve any profit, return 0.
	
	Constraints:
	1 <= prices.length <= 10^5
	0 <= prices[i] <= 10^4
*/
int main()
{
	vector<int> prices = {7, 6, 4, 3, 1};
	int max = maxProfit(prices);
	
	cout << max;
	
	return 0;
}