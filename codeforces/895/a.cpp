#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        int ans = 0;
        while(a > b){
            a -= c;
            b += c;
            ans ++;
        }
        cout << ans << endl;
    }
}