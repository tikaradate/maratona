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
        int ans = 1123456789;
        for(int i = 0; i < n; ++i){
            int d, s; cin >> d >> s;
            ans = min(ans, d + (s-1)/2);
        }
        cout << ans << endl;

    }
}