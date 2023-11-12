#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

bool is_prime(int n){
    for(int i = 2; i < n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int num_div(int n){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(n%i == 0) ans++;
    }
    return ans;
}

int main(){
    for(int i = 2; i < 11234; ++i){
        int ct = num_div(i);
        if(is_prime(ct) && ct != 2)
            cout << i << " = " << ct << ", " << sqrt(i) << endl;
    }
}
