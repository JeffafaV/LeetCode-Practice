#include <iostream>
#include <vector>

using namespace std;

// tabulation method
// time complexity: O(n) because we loop n times to reach the value for n
// space complexity: O(n) because we need a vector of size n
int fibTab(int n)
{
	// create vector and initialize first two elements or fibonacci numbers
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	
	// loop through n times starting with the third element
	for (int i = 2; i <= n; i++)
	{
		// the ith fibonacci number is calculated by adding the two previous fibonacci numbers
		// and then pushing the fibonacci number to the vector
		v.push_back(v[i-1] + v[i-2]);
	}
	
	// return the fibonacci number of n
	return v[n];
}

// space optimized method
// time complexity: O(n) because we loop n times to reach the value for n
// space complexity: O(1) because we only need three int variables
int fibSpaceOpt(int n)
{
	// the fibonacci number of n when n is 0 or 1 is n
	if (n <= 1)
	{
		return n;
	}
	
	// creating variables to hold the previous two fibonacci numbers
	int t1 = 0; // two numbers behind the current fibonacci number
	int t2 = 1; // one number behind the current fibonacci number
	int s; // holds the current fibonacci number
	
	// loop through n times starting with the third element
	for (int i = 2; i <= n; i++)
	{
		// add the two previous fibonacci numbers
		s = t1 + t2;
		// move t1 and t2 up by one fibonacci number
		t1 = t2;
		t2 = s;
	}
	
	// return the fibonacci number of n
	return s;
}

// recursive method
// time complexity: O(2^n) because each function call recursively calls itself twice
// space complexity: O(n) because it is the max height of the stack
int fibRec(int n)
{
	// the fibonacci number of n when n is 0 or 1 is n
	if (n <= 1)
	{
		return n;
	}
	
	// calculate and return the fibonacci number of n through the addition 
	// of the two previous fibonacci numbers with recursive calls
	return fibRec(n-2) + fibRec(n-1);
}

// memoization method
// time complexity: O(n) because the vector helps in reducing some excessive calls (this method 
// isn't optimized because it does 2*n calls)
// space complexity: O(n) because it is the max height of the stack
int fibMem(int n, vector<int> &v)
{
	// the fibonacci number of n when n is 0 or 1 is n
	if (n <= 1)
	{
		return n;
	}
	
	// fibonacci number for n was already calculated
	// return that fibonacci number
	if (v[n] != -1)
	{
		return v[n];
	}
	
	// insert the fibonacci number of n into the vector by adding the two 
	// previous fibonacci numbers through recursive calls
	v[n] = fibMem(n-2, v) + fibMem(n-1, v);
	
	// return the fibonacci number of n
	return v[n];
}

// memoization optimized method
// time complexity: O(n) because the vector reduces all excessive calls
// space complexity: O(n) because it is the max height of the stack
int fibMemOpt(int n, vector<int> &v)
{
	// the fibonacci number of n when n is 0 or 1 is n
	if (n <= 1)
	{
		return n;
	}
	
	// check if the second previous fibonacci number has not been calculated
	if (v[n-2] == -1)
	{
		// calculate the second previous fibonacci number and save it to 
		// the vector with a recursive call
		v[n-2] = fibMemOpt(n-2, v);
	}
	
	// check if the first previous fibonacci number has not been calculated
	if (v[n-1] == -1)
	{
		// calculate the second previous fibonacci number and save it to 
		// the vector with a recursive call
		v[n-1] = fibMemOpt(n-1, v);
	}
	
	// insert the fibonacci number of n in the vector by adding the two previous 
	// fibonacci numbers that are saved in the vector
	v[n] = v[n-2] + v[n-1];
	
	// return the fibonacci number of n
	return v[n];
}

/*
	The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
	such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
	F(0) = 0, F(1) = 1
	F(n) = F(n - 1) + F(n - 2), for n > 1.
	Given n, calculate F(n).
	
	Constraints:
	0 <= n <= 30
*/
int main()
{
	int n = 6;
	vector<int> v1(n+1, -1);
	vector<int> v2(n+1, -1);
	
	cout << fibTab(n) << endl;
	cout << fibSpaceOpt(n) << endl;
	cout << fibRec(n) << endl;
	cout << fibMem(n, v1) << endl;
	cout << fibMemOpt(n, v2) << endl;
	
	return 0;
}