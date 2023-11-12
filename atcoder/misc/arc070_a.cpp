#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    ll s = 0;
    for(int i = 0; i <= n; ++i){
        s += i;
        if(s >= n){
            cout << i << endl;
            return 0;
        }
    }
}