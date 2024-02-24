class Solution {
    
    // space optimization method
    public int climbStairsSO(int n) {
        if (n <= 1) {
            return 1; // Base cases 
        }

        int prev1 = 1; // Number of ways to reach step (n-1)
        int prev2 = 1; // Number of ways to reach step (n-2)
        int current; 

        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2; 
            prev2 = prev1; // Update for the next iteration
            prev1 = current;
        }

        return prev1;
    }

    // tabulation method
    public int climbStairsTab(int n) {
        // Array to store the number of ways to reach each step
        int[] ways = new int[n + 1];

        // Base cases
        ways[0] = 1;
        ways[1] = 1;

        // Dynamic programming loop
        for (int i = 2; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }

        return ways[n];
    }
}

public class ClimbingStairs {
	
    public static void main(String[] args) {
		
        Solution s = new Solution();
        int n = 5;

        System.out.println(s.climbStairsSO(n));
        System.out.println(s.climbStairsTab(n));
	}
}
