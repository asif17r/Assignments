//Date: 2021-06-01 23:10:04
#define ll long long 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ll n = obstacleGrid.size();
        ll m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        ll dp[n][m];
        dp[n-1][m-1] = 1;
        for(ll i = n-1; i >= 0; i--){
            for(ll j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1) continue;
                if(obstacleGrid[i][j] == 1) continue;
                ll left = 0, down = 0;
                if(j+1 < m && obstacleGrid[i][j+1] != 1) left = dp[i][j+1]; 
                if(i+1 < n && obstacleGrid[i+1][j] != 1) down = dp[i+1][j]; 
                dp[i][j] = left+down;
            }
        }
        return dp[0][0];
    }
};