#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll a, b, x;
ll f(ll n){
    return a*n + b*to_string(n).length();
}

int main(){
    cin >> a >> b >> x;
    ll lo, hi;
    lo = 1;
    hi = 1000000000;
    ll ans = 0;
    while(lo <= hi){
        ll mi = (lo+hi)/2LL;
        // cout << mi << endl;
        if(f(mi) <= x){
            ans = mi;
            lo = mi+1;
        } else {
            hi = mi-1;
        }
    }

    cout << ans << endl;
}