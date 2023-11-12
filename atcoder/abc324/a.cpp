#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    bool can = true;
    for(int i = 1; i < n; ++i){
        if(a[i] != a[0]) can = false;
    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}