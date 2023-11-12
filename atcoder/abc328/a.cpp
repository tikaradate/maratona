#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    int s = 0;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(a <= x) s += a;
    }
    cout << s << endl;
}