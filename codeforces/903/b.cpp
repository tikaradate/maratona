#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        vector<int> v(3);
        int m = 1e9+7;
        for(int i = 0; i < 3; ++i){
            cin >> v[i];
            m = min(m, v[i]);
        }

        bool can = true;
        int qt = 0;
        for(int i = 0; i < 3; ++i){
            if(v[i] % m != 0) can = false;
            qt += (v[i]/m - 1);     
        }

        if(qt > 3) can = false;

        if(!can) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
}