//Date: 2021-06-01 23:27:59
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define int long long
#define pb push_back
ll mod = 1000;
#define mp make_pair

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
            res %= mod;
        }
        a = a * a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
 
void solve(int tt){
    ll n,k; cin >> n >> k;
    ll digitnumber = floor(1.00*k*log10(n)) + 1;
    double up = k*log10(n);
    up -= digitnumber;
    up = pow(10, up);
    ll first3 = up*1000;
    ll last3 = power(n,k);
    printf("Case %lld: %lld %03lld\n", tt, first3, last3);
}

int32_t main(){
    int tt = 1;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> tt;
    for(int i = 1; i <= tt; i++){
        solve(i);
    }
}