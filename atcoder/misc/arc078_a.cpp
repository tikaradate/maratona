#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> s(n+1, 0);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i){
        s[i] = s[i-1] + a[i-1];
    }

    ll ans = 1123456789123456789;
    for(int i = 1; i < n; ++i){
        ll l, r;
        l = s[i] - s[0];
        r = s[n] - s[i];
        ans = min(ans, abs(l-r));
    }

    cout << ans << endl;
}