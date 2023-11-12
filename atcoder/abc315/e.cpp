#include <bits/stdc++.h>

using namespace std;

#define MAXN 212345

vector<vector<int>> g(MAXN);
vector<bool> vis(MAXN);
vector<int> ans;

void dfs(int u){
    vis[u] = true;

    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    ans.push_back(u);
} 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int m; cin >> m;
        for(int j = 1; j <= m; ++j){
            int a; cin >> a;
            g[i].push_back(a);
        }
    }

    dfs(1);

    for(int i = 0 ; i < ans.size()-1; ++i){
        cout << ans[i] << ' ';
    }

    cout << endl;

}