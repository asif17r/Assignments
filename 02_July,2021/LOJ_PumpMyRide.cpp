//Problem link:https://lightoj.com/problem/pimp-my-ride
//Date: 2021-07-02 03:30:35
//Author: Ashiq
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)

ll n, p;
ll up ;
ll mat[15][15];
ll dp[1LL<<14];
ll dp2[15][1LL<<14];
ll solve2(ll mask){
    if(mask == up) return 0;
    if(dp[mask] != -1) return dp[mask];
    ll ans = 1e18;
    for(int i = 0; i < n; i++){
        if(!(mask&(1<<i))){
            ll add_cost = 0;
            if(dp2[i][mask] != -1) add_cost = dp2[i][mask];
            else{
                for(int j = 0; j < n; j++){
                    if(mask&(1<<j)){
                        add_cost += mat[i][j];
                    }
                }
                dp2[i][mask] = add_cost;
            }
            ans = min(ans, add_cost + mat[i][i] + solve2(mask|(1<<i)));
        }
    }
    return dp[mask] = ans;
}

void solve(int tt){
    cin >> n;
    up = (1LL<<n)-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= up; j++){
            dp[j] = -1;
            dp2[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cin >> mat[i][j];
        }
    }
    ll ans = 1e18;
    for(int i = 0; i <n; i++){
        ans = min(ans, mat[i][i] + solve2(1<<i));
    }
    cout <<"Case "<< tt<<": "<< ans << endl;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    ll nn = 1;
    cin >> nn;
    for(int i = 0; i < nn; i++)solve(i+1);
}

