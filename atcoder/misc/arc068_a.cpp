#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    ll x, r = n%11;
    x = 0;
    if(r > 7) x = 2;
    else if (r > 0) x = 1;
    cout << (n/11)*2 + x << endl;
}