#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        ll same = lcm(x, y);
        ll f_terms = n/x - n/same;
        ll f = (((n + (n-f_terms+1)))*(f_terms))/2;

        ll s_terms = n/y - n/same;
        ll s = ((1 + s_terms)*(s_terms))/2;

        // cout << f_terms << ' ' << s_terms << endl;
        // cout << f << ' ' << s << endl;
        cout << f - s << endl;
    }
}