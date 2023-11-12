#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define int long long

int memo[1000000+15];
int n;

// int solve(int k){
//     if(k == n) return 1;
//     if(k > n) return 0;
//     if(memo[k] != -1) return memo[k];
//     int ans = 0;
//     for(int i = 1; i <= 6; ++i){
//         ans += (solve(k+i) % MOD);
//     }
//     ans = ans % MOD;
//     return memo[k] = ans;
// }

signed main(){
    cin >> n;
    memset(memo, -1, n*sizeof(int));
    for (int k = n; k >= 0; k--) {
        if(k == n) { memo[k] = 1; continue; }
        int ans = 0;
        for(int i = 1; i <= 6; ++i) if (k+i <= n) {
            ans += memo[k+i] % MOD;
        }
        ans = ans % MOD;
        memo[k] = ans;
    }
    cout << memo[0] << endl;
}