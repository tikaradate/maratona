#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n-1);
    // int x = 0;
    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
        // x ^= a[i];
    }
    vector<int> b(n);
    vector<int> num(n);
    for(int i = 0; i < n; ++i){
        num[i] = i;
    }
    // mt19937 g(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(num.begin(), num.end(), g);
    // for(int j = 0; j < n; j++){
    for(int j = 0; j < n; j = (j == 0? 1 : j << 1)){
        vector<int> vis(n, false);
        // b[0] = num[j];
        b[0] = j;
        vis[b[0]] = true;
        bool can = true;
        for(int i = 1; i < n; ++i){
            b[i] =  a[i-1] ^ b[i-1];
            // cout << b[i] << ' ' << vis[b[i]] << endl;
            if(b[i] >= n || vis[b[i]]){
                can = false;
                break;
            }
            vis[b[i]] = true;
        }
        if(can){
            for(int i = 0; i < n; ++i){
                cout << b[i] << ' ';
            }
            cout << endl;
            return 0;
        }
    }

}