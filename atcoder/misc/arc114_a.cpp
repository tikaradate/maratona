#include <bits/stdc++.h>

using namespace std;

long long p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    long long ans = 1e18;
    for(int i = 0; i < (1 << 15); ++i){
        long long cur = 1;
        for(int j = 0; j < 15; ++j){
            if(i & (1 << j)){
                cur *= p[j];
            }
        }

        bool can = true;
        for(int j = 0; j < n; ++j){
            if(gcd(cur, a[j]) == 1) can = false; 
        }

        if(can) ans = min(ans, cur);
    }

    cout << ans << endl;

}