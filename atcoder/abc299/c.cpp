#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = -1;
    int cur = 0;
    bool start = false;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'o'){
            if(start){
                cur++;
            }
            if(cur > 0) ans = max(ans, cur);
        } else if(s[i] == '-'){
            cur = 0;
            start = true;
        }
    }
    cur = 0;
    start = false;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'o'){
            if(start){
                cur++;
            }
            if(cur > 0) ans = max(ans, cur);
        } else if(s[i] == '-'){
            cur = 0;
            start = true;
        }
    }
    cout << ans << endl;
}