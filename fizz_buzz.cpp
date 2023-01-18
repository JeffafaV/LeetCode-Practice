#include <iostream>
#include <vector>
#include <string>

using namespace std;

// time complexity: O(n) because of the for loop
// space complexity: O(1) because the algorithm doesn't use extra space of size n
// (not including output space)
vector<string> fizzBuzz(int n)
{
	// holds fizz buzz answers
	vector<string> fb;
	
	// loop through the numbers
	for (int i = 1; i <= n; i++)
	{
		// divisible by both
		if (i % 3 == 0 && i % 5 == 0)
		{
			fb.push_back("FizzBuzz");
		}
		// divisible by 3
		else if (i % 3 == 0)
		{
			fb.push_back("Fizz");
		}
		// divisible by 5
		else if (i % 5 == 0)
		{
			fb.push_back("Buzz");
		}
		// divisible by none
		else
		{
			fb.push_back(to_string(i));
		}
	}
	
	return fb;
}

/*
	Given an integer n, return a string array answer (1-indexed) where:

	answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
	answer[i] == "Fizz" if i is divisible by 3.
	answer[i] == "Buzz" if i is divisible by 5.
	answer[i] == i (as a string) if none of the above conditions are true.
*/
int main()
{
	int num = 15;
	vector<string> fb = fizzBuzz(15);
	
	for (int i = 0; i < fb.size(); i++)
	{
		cout << fb[i] << " ";
	}
	
	return 0;
}