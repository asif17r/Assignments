//Problem link :https://leetcode.com/problems/edit-distance/
//Date: 2021-07-03 22:29:44
//Author: Ashiq
class Solution {
public:
    int minDistance(string one, string two) {
        int dp[501][501];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i <= 500; i++){
            dp[0][i] = i; dp[i][0] = i;
        }
        one = "$"+one; two = "@"+two;
        int n = one.size(); 
        int m = two.size(); 
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = dp[i-1][j-1] + ((one[i] == two[j])^1);
                dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1});
            }
        }
        return dp[n-1][m-1];
    }
};