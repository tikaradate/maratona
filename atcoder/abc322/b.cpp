#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using vi = vector<int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    bool is_p = false, is_s = false;

    is_p = s == t.substr(0, n);
    string suff = t.substr(m-n, n);
    is_s = s == suff;

    if(is_p && is_s) cout << 0 << endl;
    else if(is_p) cout << 1 << endl;
    else if(is_s) cout << 2 << endl;
    else cout << 3 << endl;
}