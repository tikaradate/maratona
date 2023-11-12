#include <bits/stdc++.h>

using namespace std;

const int N = 212345;

vector<bool> vis(N);
vector<vector<int>> g(N);

void dfs(int u){
    cout << u+1 << ' ';
    vis[u] = true;
    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
            cout << u+1 << ' ';
        }
    }
    // if(qt > 0)
        
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; ++i){
        sort(g[i].begin(), g[i].end());
    }

    dfs(0);
    cout << endl;
}