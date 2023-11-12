#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        string s; cin >> s;
        vector<int> pxor(n+1);
        for(int i = 1; i <= n; ++i){
            pxor[i] = pxor[i-1] ^ a[i-1];
        }
        int x0 = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') {
                x0 ^= a[i];
            }
        }

        int q; cin >> q;
        while(q--){
            int op; cin >> op;
            if(op == 1){
                int l, r; cin >> l >> r;
                x0 ^= pxor[l-1] ^ pxor[r];
            } else {
                int g; cin >> g;
                if(g == 0){
                    cout << x0 << ' ';
                } else {
                    cout << (x0 ^ pxor[n]) << ' ';
                }
            }
        }
        cout << endl;
    }
}