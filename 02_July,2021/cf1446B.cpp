//Problem link: https://codeforces.com/problemset/problem/1446/B
//Date: 2021-07-02 04:29:52
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one,two;

int dp[5001][5001][2];
int lcs(int a, int b, int stat){
    if(a >= n || b >= m) return 0;
    if(dp[a][b][stat] != -1) return dp[a][b][stat];
    int ans = 0;
    if(stat == 0){
        ans = max(ans, lcs(a+1,b,stat));
        ans = max(ans, lcs(a,b+1,stat));
        if(one[a] == two[b]){
            ans = max(ans, 2+lcs(a+1,b+1,1));
        }
    }
    else{
        ans = max(ans, lcs(a+1,b,stat)-1);
        ans = max(ans, lcs(a,b+1, stat)-1);
        if(one[a] == two[b]){
            ans = max(ans, 2);
            ans = max(ans, 2+lcs(a+1,b+1,1));
        }
    }
    return dp[a][b][stat] = ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> one >> two;
    memset(dp,-1,sizeof dp);
    cout << lcs(0,0,0) << endl;
} 