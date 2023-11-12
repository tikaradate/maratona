#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int n = 11231234;
    vector<bool> is_prime(n+1, true);
    set<int> composite;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    while(t--){
        int l, r; cin >> l >> r;
        if(r <= 3){
            cout << -1 << endl;
        } else if(r-l >= 1){
            cout << r/2 << ' ' << r/2 << endl;
        } else {
            if(is_prime[r]){
                cout << -1 << endl;
            } else {
                if(r%2 == 0){
                    cout << 2 << ' ' << r-2 << endl;
                } else {
                    int fac = -1;
                    for (long long d = 2; d * d <= r && fac == -1; d++) {
                        while (r % d == 0) {
                            fac = d;
                            break;
                        }
                    }
                    cout << fac << ' ' << r - fac << endl;
                }
            }
        }
    }
}