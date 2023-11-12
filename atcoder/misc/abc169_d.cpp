#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    map<ll, ll> f;
    for(ll i = 2; i*i <= n; ++i){
        while(n%i == 0){
            f[i]++;
            n /= i;
        }
    }
    if(n > 1) f[n]++;

    ll ans = 0;
    for(auto [p, e] : f){
        int cur = e;
        for(int i = 1; cur > 0; i++){
            cur -= i;
            if(cur >= 0)
                ans++;
        }
    }

    cout << ans << endl;
}