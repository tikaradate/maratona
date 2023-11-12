#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll c; cin >> c;
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(c % a == 0){
            ll s1 = a;
            ll s2 = c/a;
            if(s1 > s2) swap(s1, s2);
            cout << s1 << ' ' << s2 << endl;
            return 0;
        }
    }
}