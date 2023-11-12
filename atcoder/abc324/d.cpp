#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    sort(s.rbegin(), s.rend());
    // cout << s << endl;
    long long ans = 0;
    long long lim = (long long)sqrt(stoll(s));
    // if(s == "0") ans++;
    for(long long i = 0; i <= lim; ++i){
        string a = to_string(i*i);
        // cout << a << endl;
        int asz = a.size();
        for(int j = 0; j < s.size() - asz && s.size() >= asz; j++){
            a.push_back('0');
        }
        // cout << a << ' ' << s << endl;
        sort(a.rbegin(), a.rend());
        if(a == s) ans++;
    }

    cout << ans << endl;
}