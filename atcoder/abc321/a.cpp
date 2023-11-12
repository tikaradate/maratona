#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    bool can = true;
    for(int i = 1; i < s.size(); ++i){
        if(s[i]-'0' >= s[i-1]-'0') can = false;
    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}