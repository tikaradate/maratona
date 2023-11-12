#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    ll ans = 0;
    for(int i = 0; i < s.size()-3; ++i){
        if(s[i] == 'k' && s[i+1] == 'i' && s[i+2] == 'c' && s[i+3] == 'k') ans++;
    }

    cout << ans << endl;
}