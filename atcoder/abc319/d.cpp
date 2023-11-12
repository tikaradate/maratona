#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    int m, n; cin >> n >> m;
    vector<ll> words(n);
    ll m_w = 0;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> words[i];
        words[i]++;
        m_w = max(m_w, words[i]);
        sum += words[i];
    }   

    ll lo = m_w-1;
    ll hi = sum;
    while(lo+1 < hi){
        ll mi = lo + (hi-lo)/2;
        int rows = 1;
        ll cur_len = 0;
        for(int i = 0; i < n; ++i){
            cur_len += words[i];
            if(cur_len > mi){
                rows++;
                cur_len = words[i];
            }
        }
        if(rows > m){
            lo = mi;
        } else {
            hi = mi;
        }
    }

    cout << lo << endl;
}