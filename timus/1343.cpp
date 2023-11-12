#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool is_prime(string s){
    ll n = stoll(s);
    // cout << n << ' ' << sqrt(n) << endl;
    for(int i = 2; i < 2*sqrt(n); ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;

    char num[13];
    for(int i = 0; i < 12; ++i){
        if(i < n) num[i] = s[i];
        else num[i] = '0';
    }
    num[11] = '3';
    num[12] = '\0';

    int ct = 3;
    while(true){
        if(is_prime(num)){
            for(int i = 0; i < 12; ++i){
                cout << num[i];
            }
            cout << endl;
            return 0 ;
        }
        ct += 2;
        string suff = to_string(ct);
        int j = 0;
        for(int i = 0; i < 12; ++i){
            if(i < n) num[i] = s[i];
            else if(i >= 12 - suff.size()) num[i] = suff[j++];
            else num[i] = '0';
        }
    }
}