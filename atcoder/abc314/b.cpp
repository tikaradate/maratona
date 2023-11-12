#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    vector<set<int>> bets(100);
    vector<int> n_bets(100, 0);
    int n; cin >> n; 
    for(int i = 0; i < n; ++i){
        int c; cin >> c;
        n_bets[i] = c;
        for(int j = 0; j < c; ++j){
            int cur; cin >> cur;
            bets[i].insert(cur);
        }
    }

    int x; cin >> x;
    // vector<vector<int>> possible(100, vector<int>(37, 0));
    vector<pair<int, int>> possible;
    int qt = 0;
    for(int i = 0; i < n; ++i){
        if(bets[i].find(x) != bets[i].end()){
            possible.push_back({n_bets[i], i});
            qt++;
        }
    }
    if(qt != 0){
        sort(possible.begin(), possible.end());
        vector<int> ans;
        int fi = possible[0].first;
        ans.push_back(possible[0].second);
        for(int i = 1; i < n; ++i){
            if(possible[i].first != fi){
                break;
            }
            ans.push_back(possible[i].second);
        }

        cout << ans.size() << endl;
        for(int i = 0 ; i < ans.size(); ++i){
            cout << ans[i] + 1 << ' ';
        }

        cout << endl;
    } else {
        cout << 0 << endl;
    }
}