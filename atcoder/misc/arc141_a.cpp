#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int t; cin >> t;

    while(t--){
        string s;
        cin >> s;
        ll ans = 0;
        for(int k = 1; k < s.size(); ++k){
            if(s.size()%k != 0) continue;
            ll m = stoll(s.substr(0, k));
            ll m2 = m-1;
            string t, t2;
            for(int i = 0; i < s.size(); i+=k){
                t += to_string(m);
                t2 += to_string(m2);
            }
            // cout << t << ' ' << t2 << endl;
            if(t > s) t = "0";
            if(t2 > s) t2 = "0";

            ans = max(ans, max(stoll(t), stoll(t2)));
        }
        if(ans == 0){
            for(int i = 0; i < s.size()-1; ++i){
                cout << "9";
            }
            cout << endl;
        }
        else
            cout << ans << endl;
    }
}