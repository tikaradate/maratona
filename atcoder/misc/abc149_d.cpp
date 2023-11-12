#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int n, k;
    int v[3];
    cin >> n >> k >> v[0] >> v[1] >> v[2]; // r s p
    string t; cin >> t;
    ll ans = 0;
    for(int i = 0; i < k; ++i){
        char last = '*';
        for(int j = i; j < n; j += k){
            char c = t[j];
            bool all_eq = true;
            if(c == 'r'){
                if(last != 'p'){
                    ans += v[2];
                    last = 'p';
                    all_eq = false;
                }
            }
            if(c == 's')
                if(last != 'r'){
                    ans += v[0];
                    last = 'r';
                    all_eq = false;
                }
            if(c == 'p')
                if(last != 's'){
                    ans += v[1];
                    last = 's';
                    all_eq = false;
                }
            if(all_eq && j+k < n){
                if(t[j+k] == 'r')
                    last = 'r';
                if(t[j+k] == 's')
                    last = 's';
                if(t[j+k] == 'p')
                    last = 'p';
            }
            // cout << j << ' ' << c << ' ' << last <<  ' ' << ans << endl;
        }
    }

    cout << ans << endl;
}