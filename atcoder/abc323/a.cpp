#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    bool can = true;
    for(int i = 1; i < 16; i += 2){
        can &= (s[i] == '0');
    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}