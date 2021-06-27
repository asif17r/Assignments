//Problem link:https://lightoj.com/problem/an-easy-lcs
//Date: 2021-06-27 22:06:18
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
string dp[102][102];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    for(int k = 1; k <= tc; k++){
        cin >> one >> two;
        one = "$"+one; two = "@"+two;
        n = one.size(); 
        m = two.size(); 
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(one[i] == two[j]){
                    dp[i][j] = dp[i-1][j-1] + one[i];
                }
                else{
                    string on = dp[i-1][j];
                    string tw = dp[i][j-1];
                    if(on.size() == tw.size()) dp[i][j] = min(on,tw);
                    else on.size()>tw.size()?dp[i][j] = on:dp[i][j] = tw;
                }
            }
        }
        string ans = dp[n-1][m-1];
        if(ans == "") ans = ":(";
        cout << "Case "<< k <<": ";
        cout << ans << endl;
    }
}