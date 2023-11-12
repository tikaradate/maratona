#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<ii> c(n), r(n);
    bool exists = false;
    for(int i = 0; i < n; ++i){
        cin >> c[i].first;
        c[i].second = i;
        if(c[i].first == t) exists = true;
    }

    for(int i = 0; i < n; ++i){
        cin >> r[i].first;
        r[i].second = i;
    }

    if(!exists){
        t = c[0].first;
    }
    
    int r_i = -1;
    for(int i = 0; i < n; ++i){
        if(c[i].first == t){
            if(r_i == -1){
                r_i = i;
            }
            else if(r[r_i].first < r[i].first){
                r_i = i;
            }
        }
    }

    cout << r_i+1 << endl;
}