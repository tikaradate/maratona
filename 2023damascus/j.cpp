#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int high_bit(int n){
    int cur_bit = 0;
    // int ans = 0;
    while(1<<cur_bit <= n){
        // cout << (1 << cur_bit) << endl;
        // cout << n << endl;
        // if((1<<cur_bit & n) == 1){
        //     cout << "oi" << endl;
        //     ans = cur_bit;
        // }
        cur_bit++;
    }
    return cur_bit;
}

int main(){
    int t; cin >> t;

    // cout << high_bit(2) << endl;
    // exit(1);

    while(t--){
        int n; cin >> n;
        //vector<int> a(n);
        vector<int> bits(30, 0);
        for(int i = 0; i < n; ++i){
            int a; cin >> a;
            bits[high_bit(a)-1]++;
        }

        int ans = 1;
        for(int i = 0; i < 30; ++i){
            if(bits[i] > ans){
                ans = bits[i];
            }
        }

        cout << ans << endl;
    }

}