#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int memo[1123456];
vector<int> a;
int solve(int i){
    if(i == n) return 0;
    if(i > n) return 1e9;
    if(memo[i] != -1) return memo[i];
    return memo[i] = min(solve(i+1)+1, solve(i+a[i]+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        memset(memo, -1, n*sizeof(int));
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }

        cout << solve(0) << endl;

        // for(int i = 0; i < n; ++i){
        //     cout << memo[i] << ' ';
        // }
        // cout << endl;

    }
}