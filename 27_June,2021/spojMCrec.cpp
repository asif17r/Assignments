//problem link: https://www.spoj.com/problems/MC/
//Date: 2021-06-27 21:29:24
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
int dp[1001][1001];
int solve(int a, int b){
    if(a >= n || b >= m) {
        return ((n-a)*15) + ((m-b)*30);
    }
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 0;
    if(one[a] == two[b]) ans = solve(a+1,b+1);
    else ans = min(30+solve(a,b+1), 15+solve(a+1,b));
    return dp[a][b] = ans;
}

int main(){
    while(cin >> one){
        if(one == "#") break;
        cin >> two;
        n = one.size();
        m = two.size();
        memset(dp, -1, sizeof dp);
        cout << solve(0,0) << endl;
    }
}