#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll x, y; cin >> x >> y;
    if(x == y){
        cout << 0 << endl;
    } else if(x >= 0) {
        if(y > 0){
            if(x > y) cout << x-y+2 << endl;
            else cout << y - x << endl;
        } else {
            if(x > abs(y)) cout << x + y + 1 << endl;
            else cout << abs(x+y) + 1 << endl;
        }
    } else {
        if(y > 0){
            if(abs(x) > y) cout << abs(x) - y + 1<< endl;
            else cout << 1+y-abs(x) << endl;
        } else {
            if(abs(x) > abs(y)) cout << abs(x) - abs(y) << endl;
            else cout << 1 + abs(y) - abs(x) + 1 << endl;
        }
    }
}