//Date: 2021-06-27 21:29:08
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
int n, m;
string one, two;
int dp[5001][5001];


int main(){
    cin >> one >> two;
    one = "$"+one; two = "@"+two;
    n = one.size(); 
    m = two.size(); 
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(one[i] == two[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
}
