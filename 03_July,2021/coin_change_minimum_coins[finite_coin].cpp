//Problem link : Coin Change dp with finite number of coinst 
//Major Change : just reversed the nested for loop of infinite version
//Date: 2021-07-03 22:32:49
//Author: Ashiq
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        dp[0] = 0;
        for(auto a: coins){
            for(int i = amount; i >= a; i--){
                dp[i] = min(dp[i], dp[i-a]+1);
            }
        }
        if(dp[amount] >= 1e9) dp[amount] = -1;
        return dp[amount];
    }
};