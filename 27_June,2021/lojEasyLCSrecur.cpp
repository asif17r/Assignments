//problem link : https://lightoj.com/problem/an-easy-lcs
//Date: 2021-06-27 21:29:15
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
string dp[101][101];
string solve(int a, int b){
    if(a >= n || b >= m) return "";
    if(dp[a][b] != "$") return dp[a][b];
    string ans = "";
    if(one[a] == two[b]) {
        ans = one[a]+ solve(a+1,b+1);
    }
    else{
        string on = solve(a+1,b);
        string tw = solve(a,b+1);
        if(on.size() == tw.size()) ans = min(on,tw);
        else on.size()>tw.size()?ans = on:ans = tw;
    } 
    return dp[a][b] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> one >> two;
        n = one.size();
        m = two.size();
        for(int k = 0; k <= n; k++){
            for(int j= 0; j <= m; j++){
                dp[k][j] = "$";
            }
        }
        string ans = solve(0,0);
        if(ans == "") ans = ":(";
        cout << "Case "<< i <<": "<< ans << endl;
    }
}