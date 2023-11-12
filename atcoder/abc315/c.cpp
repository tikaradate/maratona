#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ii> ice_cream(n);
    for(int i = 0; i < n; ++i){
        int f, s; cin >> f >> s;
        ice_cream[i] = {s, f};
    }
    sort(ice_cream.rbegin(), ice_cream.rend());

    int pos_same = -1, pos_diff = -1, first = ice_cream[0].first;
    for(int i = 1; i < n; ++i){
        if(ice_cream[i].second == ice_cream[0].second){
            if(pos_same == -1) pos_same = ice_cream[i].first;
        } else {
            if(pos_diff == -1) pos_diff = ice_cream[i].first;
        }
    }

    if(first + pos_same/2 > first + pos_diff){
        cout <<  first + pos_same/2 << endl;
    } else {
        cout <<  first + pos_diff << endl;
    }
}