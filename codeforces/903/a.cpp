#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string x, s; cin >> x >> s;
        bool can = false;
        for(int i = 0; i < 6; ++i){
            if(x.find(s) != string::npos){ 
                cout << i << endl;
                can = true;
                break;
            }
            x = x + x;
        }

        if(!can) cout << -1 << endl;
    }
}