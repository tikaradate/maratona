#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll a, b; cin >> a >> b;
    ll ab = pow(a,b);
    ll ba = pow(b,a);
    cout << ab + ba << endl;
}