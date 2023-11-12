#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll x; cin >> x;

    for(ll i = -150; i < 150; ++i){
        for(ll j = -150; j < 150; ++j){
            ll j5 = j*j*j*j*j;
            ll i5 = i*i*i*i*i;
            if(i5 - j5 == x){ 
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
}