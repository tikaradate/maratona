#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;

    int ans = 1;
    for(int i = 2 ; i <= s.size(); ++i){
        for(int j = 0; j < s.size()-i+1; ++j){
            string t = s.substr(j, i);
            string v = t;
            reverse(v.begin(), v.end());
            if(t == v) ans = i;
        }
    }

    cout << ans << endl;
}