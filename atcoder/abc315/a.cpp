#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s; cin >> s;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'a') continue;
        if(s[i] == 'e') continue;
        if(s[i] == 'i') continue;
        if(s[i] == 'o') continue;
        if(s[i] == 'u') continue;
        cout << s[i];
    }
    cout << endl;
}