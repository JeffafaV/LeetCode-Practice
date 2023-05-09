#include <iostream>
#include <vector>

using namespace std;

// diagonal index method
// time complexity: O(n) because we can loop through the diagonals
// space complexity: O(1) because regardless of n we use 3 int variables
int diagonalSum(vector<vector<int>> mat)
{
	// holds the sum of the diagonal
	int sum = 0;
	// holds the first index of the second diagonal
	int j = mat.size()-1;
	
	// loop through size of vector
	// we can get the diagonals with i and j
	// First diagonal = (i,i), (i+1,i+1), (i+2,i+2), etc.
	// Second diagonal = (j,i), (j-1, i+1), (j-2, i+2), etc.
	for (int i = 0; i < mat.size(); i++)
	{
		// if i and j are not the same that means we are not at 
		// the same position
		if (i != j)
		{
			// add both positions' element
			sum += mat[i][i] + mat[j][i];
		}
		// if i and j are the same that means we are at the 
		// same position
		else
		{
			// only add one position since both point to the same position
			sum += mat[i][i];
		}
		// decrement j
		j--;
	}

	return sum;
}

/*
	Given a square matrix mat, return the sum of the matrix diagonals.
	Only include the sum of all the elements on the primary diagonal and 
	all the elements on the secondary diagonal that are not part of the 
	primary diagonal.
	
	Constraints:
	n == mat.length == mat[i].length
	1 <= n <= 100
	1 <= mat[i][j] <= 100
*/
int main()
{
	vector<vector<int>> mat;
	mat.push_back({1,2,3});
	mat.push_back({4,5,6});
	mat.push_back({7,8,9});
	
	cout << diagonalSum(mat);
	
	return 0;
}