#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans = -1;
    for(int i = n; i <= 919; ++i){
        string s = to_string(i);
        int a, b, c;
        a = s[0] - '0';
        b = s[1] - '0';
        c = s[2] - '0';
        if(a*b == c){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    

}