#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int fb = -1, sb = -1, st = -1;
    for(int i = 0; i < n; ++i){
        if(s[i] == '|'){
            if(fb == -1) fb = i;
            else sb = i;
        } else if(s[i] == '*') st = i;
    }

    if(st > fb && st < sb) cout << "in" << endl;
    else cout << "out" << endl;
}