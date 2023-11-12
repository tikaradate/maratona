#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
// #define int long long

int memo[1000000+15];
bool ok[1000000+15];
int coin[100+15];
int n, x, i;
int oo = 998244353;

int solve(int k){
    if(k == 0) return 0;
    if(k < 0) return oo;
    if(ok[k]) return memo[k];
    // cout << "??" << endl;
    int ans = oo;
    for(int i = 0; i < n; ++i){
        ans = min(ans, solve(k - coin[i]) + 1);
    }
    ok[k] = true;
    return memo[k] = ans; 
}


signed main(){
    cin >> n >> x;
    // cout << n << ' ' << x << endl;
    memset(memo, oo, sizeof(int)*n);
    for(int i = 0; i < n; ++i){
        cin >> coin[i];
    }

    cout << (solve(x) == oo? -1 : solve(x)) << endl;
}