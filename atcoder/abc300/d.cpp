#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n; cin >> n;

    int m = 300000;
    vector<bool> is_prime(m+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (is_prime[i] && (long long)i * i <= m) {
            for (int j = i * i; j <= m; j += i)
                is_prime[j] = false;
        }
    }

    vector<ll> primes;
    for(int i = 0; i < m; ++i){
        if(is_prime[i]) primes.push_back(i);
    }

    int ps = primes.size();
    cout << ps << endl;
    int ans = 0;
    for(int i = 0; i < ps; ++i){
        int k = ps - 1;
        for(int j = i+1; j < k && j < ps; ++j){
            while(j < k){
                ll num = primes[i]*primes[i]*primes[j];
                if(num > n){k--; continue;}
                num = num*primes[k];
                if(num > n){k--; continue;}
                num = num*primes[k];
                if(num > n){k--; continue;}
                break;
            }
            ans += (k-j);
        }
    }

    cout << ans << endl;
}