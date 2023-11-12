#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lili = pair<ll, ll>;

#define fi first
#define se second

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // x 1 2 3
    if(b == 1 && c == 2 && d == 3){
        cout << 1 << endl;
    // 1 x 1 2
    } else if(a == 1 && c == 1 && d == 2){
        cout << 2 << endl;
    // 2 1 x 1
    } else if(a == 2 && b == 1 && d == 1){
        cout << 3 << endl;
    // 3 2 1 x
    } else if(a == 3 && b == 2 && c == 1){
        cout << 4 << endl;
    }
}