#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
int dp[5001][5001];
int solve(int a, int b){
    if(a >= n || b >= m) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    int ans = 0;
    if(one[a] == two[b]) ans = 1+solve(a+1,b+1);
    else ans = max(solve(a,b+1), solve(a+1,b));
    return dp[a][b] = ans;
}

int main(){
    cin >> one >> two;
    n = one.size();
    m = two.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << endl;
}