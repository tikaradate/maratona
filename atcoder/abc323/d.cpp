#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    map<ll, ll> slimes;
    ll qt = 0;
    for(int i = 0; i < n; ++i){
        ll s, c;
        cin >> s >> c;
        slimes[s] += c;
        // qt += c;
    }

    for(auto it = slimes.begin(); it != slimes.end(); it++){
        // cout << "slime size: " << it->first << " with qt: " << it->second << endl;
        if(it->second > 1){
            ll cur = it->second;
            qt += cur%2;
            for(int i = 1; i <= log2(it->second); ++i){
                cur = cur/2;
                if((cur % 2) && (slimes.find(it->first*pow(2, i)) == slimes.end())) qt++;
                if(slimes.find(it->first*pow(2, i)) != slimes.end()){
                    slimes[it->first*pow(2, i)] += cur;
                    break;
                }
            }
        } else {
            qt += it->second;
        }
        // cout << qt << endl;

    }

    cout << qt << endl;
    
}
