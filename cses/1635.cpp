#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define int long long

int memo[1000000+15];
bool ok[1000000+15];
int coin[100+15];
int n, x, i;
int oo = 998244353;

int solve(int k){
    if(k == 0) return 1;
    if(k < 0) return 0;
    if(memo[k] != -1) return memo[k];
    // cout << "??" << endl;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += solve(k - coin[i]) % MOD;
    }
    // ok[k] = true;
    return memo[k] = (ans % MOD); 
}


signed main(){
    cin >> n >> x;
    // cout << n << ' ' << x << endl;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; ++i){
        cin >> coin[i];
    }

    cout << solve(x) << endl;
}