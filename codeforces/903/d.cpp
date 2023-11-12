#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<ll>> f(n);
        map<ll, ll> p;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            f[i] = trial_division1(a);
            for(int j = 0; j < f[i].size(); ++j){
                p[f[i][j]]++;
            }
        }

        int can = true;
        for(auto [k, v] : p){
            if(v % n != 0) can = false;
        }

        if(can) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}