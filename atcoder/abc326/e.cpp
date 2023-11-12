#include <bits/stdc++.h>

using namespace std;


solve(){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, y; cin >> x >> y;
    if(x > y){
        if(x-y <= 3) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        if(y-x <= 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}