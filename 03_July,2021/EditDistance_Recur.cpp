//Problem link :https://leetcode.com/problems/edit-distance/
//Date: 2021-07-03 22:29:40
//Author: Ashiq
int n, m;
int dp[501][501];
string one, two;
int solve(int a, int b){
    if(a >= n || b >= m){
        return (n-a) + (m-b);
    }
    if(dp[a][b] != -1) return dp[a][b];
    return dp[a][b] = min({solve(a+1,b+1)+((one[a] == two[b])^1) , solve(a+1,b)+1 , solve(a,b+1)+1});
}

class Solution {
public:
    int minDistance(string one1, string two1) {
        memset(dp, -1, sizeof dp);
        one = one1, two = two1;
        n = one.size(); 
        m = two.size();
        return solve(0,0);
    }
};