#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll c; cin >> c;
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(c % a == 0){
            cout << a << ' ' << c/a << endl;
            return 0;
        }
    }
}