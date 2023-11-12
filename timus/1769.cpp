#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    vector<bool> is(1000001, false);
    for(int sz = 1; sz <= 6; sz++){
        for(int i = 0; i < s.size(); ++i){
            string sub = s.substr(i, sz);
            int a = stoi(sub);
            is[a] = true;
        }
    }

    for(int i = 1; i <= 1000000; ++i){
        if(!is[i]){ cout << i << endl; break;}
    }
}