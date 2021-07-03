//Problem link :https://leetcode.com/problems/coin-change
//Date: 2021-07-03 22:32:49
//Author: Ashiq
// Here we have infinite number of coins of each type
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        dp[0] = 0;
        for(auto a: coins){
            for(int i = a; i <= amount; i++){
                dp[i] = min(dp[i], dp[i-a]+1);
            }
        }
        if(dp[amount] >= 1e9) dp[amount] = -1;
        return dp[amount];
    }
};