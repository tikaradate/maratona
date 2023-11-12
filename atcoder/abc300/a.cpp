#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    int ans = a + b;
    for(int i = 1; i <= n; ++i){
        int c; cin >> c;
        if(c == ans){ cout << i << endl; return 0;}
    }

}