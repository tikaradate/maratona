#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
// #define int long long

int memo[1000000+15][100];
// bool ok[1000000+15];
// int coin[100+15];
vector<int> coin;
int n, x, i;
int oo = 998244353;

int solve(int k, int ix){
    if(ix == n && k != 0) return 0;
    if(k == 0) return 1;
    if(k < 0) return 0;
    if(memo[k][ix] != -1) return memo[k][ix];
    // cout << "??" << endl;
    int ans = 0;
    for(int i = ix; i < n; ++i){
        ans = (ans + solve(k - coin[i], i)) % MOD;
    }
    return memo[k][ix] = ans; 
}


signed main(){
    cin >> n >> x;
    // cout << n << ' ' << x << endl;
    memset(memo, -1, sizeof(memo));
    coin.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> coin[i];
    }

    sort(coin.begin(), coin.end());

    for (int ix = 0; ix < n; ix++) {
        for (int k = 0; k < x; k++) {
            if(ix == n && k != 0) { memo[k][ix] = 0; continue; }
            if(k == 0) { memo[k][ix] = 1; continue; }
            int ans = 0;
            for(int i = ix; i < n; ++i) if (k - coin[i] >= 0) {
                ans = (ans + memo[k - coin[i]][i]) % MOD;
            }
            memo[k][ix] = ans; 
            cout << ans << ' ';
        }
        cout << endl;
    }

    cout << memo[x][n] << endl;
}