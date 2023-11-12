#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<ll, ll, ll>;

ll n, m, k, sum;
vector<bool> vis(10);

void dfs(ll u, vector<vector<ll>> &g){
    if(vis[u]) return;
    vis[u] = true;
    for(auto v : g[u]){
            dfs(v, g);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;

    vector<iii> edges(m);
    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {u, v, w};

    }
    ll ans = 1123456789123456;
    // vector<ll> ans;
    for(int i = 0; i < (1 << m); i++){
        if(__builtin_popcount(i) != n-1) continue;

        sum = 0;
        vector<vector<ll>> g(n);
        for(int j = 0; j < m; ++j){
            if(i & (1 << j)) {
                auto [u, v, w] = edges[j];
                g[u].push_back(v);
                g[v].push_back(u);
                sum = (sum + w) % k;
            }
        }

        for(int j = 0; j < n; ++j){
            vis[j] = false;
        }

        dfs(0, g);
        bool all_vis = true;
    
        for(int j = 0; j < n; ++j){
            all_vis &= vis[j];
        }
     
        if(!all_vis) continue;
        // ans.push_back(sum);
        ans = min(ans, sum);
    }

    cout << ans <<endl; 
    // sort(ans.begin(), ans.end());
    // for(int i = 0; i < ans.size(); ++i)
        // cout << ans[i] << endl;
}