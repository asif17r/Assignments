//Problem link: https://leetcode.com/problems/coin-change-2
//Date: 2021-07-03 22:55:27
//Author: Ashiq
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1);
        dp[0] = 1;
        for(auto a: coins){
            for(int i = a; i <= amount; i++){
                dp[i] += dp[i-a];
            }
        }
        return dp[amount];
    }
};