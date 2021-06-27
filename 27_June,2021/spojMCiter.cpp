//problem link: https://www.spoj.com/problems/MC/
//Date: 2021-06-27 21:30:20
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
int dp[5001][5001];


int main(){
    while(cin >> one){
        if(one == "#") break;
        cin>> two;
        one = "$"+one; two = "@"+two;
        n = one.size(); 
        m = two.size(); 
        for(int i = 0; i < n; i++) dp[i][0] = i*15;
        for(int j = 0; j < m; j++) dp[0][j] = j*30;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(one[i] == two[j]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(15+dp[i-1][j], 30+dp[i][j-1]);
                }
            }
        }
        cout << dp[n-1][m-1] << endl;
    }
}