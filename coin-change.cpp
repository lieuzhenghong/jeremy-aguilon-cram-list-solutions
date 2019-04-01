class Solution {
public:
    vector<int> memo;
    
    int mcn(vector<int>&coins, int amount)
    {
        if (memo[amount] < INT_MAX) return memo[amount];
        if (amount == 0) return 0;

        for (int &coin : coins)
        {
            if (amount-coin < 0) continue;
            else if (amount-coin == 0) memo[amount] = 1;
            else {
                int coins_needed = mcn(coins, amount-coin);
                if (coins_needed != -1 && coins_needed < memo[amount]) 
                    memo[amount] = coins_needed + 1;
                else continue;
            }
        }
        if (memo[amount] == INT_MAX) memo[amount] = -1;
        return memo[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        for (int i = 0; i <= amount; i++)
        {
            memo.push_back(INT_MAX);
        }
        return mcn(coins, amount);
    }
};
