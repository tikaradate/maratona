#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using vi = vector<int>;

int n, k, p;
ll memo[100][100];
ll dp(int i, ll cost, vector<pair<ll, vi>> &c, vector<bool> choices){
    if(i == n){
        vector<int> curr(k, 0);
        for(int i = 0; i < choices.size(); ++i){
            if(choices[i]){
                for(int j = 0; j < k; ++j){
                    curr[j] += c[i].second[j];
                }
            }
        }
        bool can = true;
        for(int j = 0; j < k; ++j){
            if(curr[j] < p){
                can = false;
                break;
            }
        }
        if(can) return cost;
        else return 1123456789123;
    }
    if(memo[i][cost] != -1) return memo[i][cost];
    vector<bool> choices2 = choices;
    choices.push_back(1);
    choices2.push_back(0);
    ll ans = min(dp(i+1, cost+c[i].first, c, choices), dp(i+1, cost, c, choices2));
    memo[i][cost] = ans;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> p;
    vector<pair<ll, vi>> c(n);
    memset(memo, -1, 100*100*8);
    for(int i = 0; i < n; ++i){
        cin >> c[i].first;
        for(int j = 0; j < k; ++j){
            int v;
            cin >> v;
            c[i].second.push_back(v); 
        }
    }

    vector<bool> choices;
    ll ans = dp(0, 0, c, choices);
    cout <<  (ans == 1123456789123? -1 : ans) << endl;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 100; ++j){
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }

}