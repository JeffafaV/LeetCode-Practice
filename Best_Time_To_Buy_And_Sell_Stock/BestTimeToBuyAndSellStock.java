class Solution {
    
    public int maxProfit(int[] prices) {
        
        int minPrice = Integer.MAX_VALUE; // Start with a very high minimum price
        int maxProfit = 0;

        for (int price : prices) {
            
            minPrice = Math.min(minPrice, price);  // Keep track of the lowest buying price seen
            maxProfit = Math.max(maxProfit, price - minPrice);  // Update max profit if better
        }

        return maxProfit;
    }
}

public class BestTimeToBuyAndSellStock {
	
    public static void main(String[] args) {
		
        Solution s = new Solution();
        int[] prices = new int[] {7, 6, 4, 3, 1};

        System.out.println(s.maxProfit(prices));
	}
}
