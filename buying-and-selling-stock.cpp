/*
 * 121. Best Time to Buy and Sell Stock
 *
 * Say you have an array for which the ith element is the price of a given stock on day i. 
 * If you were only permitted to complete at most 
 * one transaction (i.e., buy one and sell one share of 
 * the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        
        int min_price = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            int price = prices[i];
            if (price > min_price)
            {
                max_profit = max(price - min_price, max_profit);
            }
            else
            {
                min_price = price;
            }
        }
        return max_profit;
    }

};
