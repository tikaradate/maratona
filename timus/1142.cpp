#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()

ll f[11];


ll solve(ll n){
    ll ans = 0;
    for(int i = 0; i < (1 << n-1); ++i){
        int g = 1;
        for(int j = 0; j < n-1; ++j){
            if(((1 << j) & i) == 0){
                g++;
                cout << " < ";
            } else {
                cout << " = ";
            }
        }
        cout << endl;
        // ans += f[n]/f[g];
        ans += f[g];
        cout << f[g] << endl;
        // cout << g << ' ' << i << endl;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    f[0] = 1; f[1] = 1;
    for(int i = 2; i <= 10; ++i){
        f[i] = f[i-1]*i;
    }

    ll a[12];
    for(int i = 3; i <= 3; ++i){
        a[i] = solve(i);
        cout << a[i] << endl;
    } 
}