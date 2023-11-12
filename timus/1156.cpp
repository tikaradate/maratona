#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'

vector<vector<int>> g(100, vector<int>());

bool vis[100], b[100], w[100], team, can;
int qt_b, qt_w;

void dfs(int u){
    team = !team;
    vis[u] = true;
    if(team){
        b[u] = true;
        qt_b++;
    } else {
        w[u] = true;
        qt_w++;
    }
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v);
        } else {
            if((b[u] && b[v]) || (w[v] && w[u])) can = false;
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    memset(vis, 100, 0);
    memset(b, 100, 0);
    memset(w, 100, 0);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    can = true;
    team = false;
    for(int i = 0; i < 2*n; ++i){
        if(!vis[i]){
            qt_b = 0;
            qt_w = 0;
            dfs(i);
        }
    }
    if(can && (qt_b == qt_w)){
        for(int i = 0; i < 100; ++i){
            if(b[i]) cout << i + 1 << ' ';
        }
        cout << endl;
        for(int i = 0; i < 100; ++i){
            if(w[i]) cout << i + 1 << ' ';
        }
        cout << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}