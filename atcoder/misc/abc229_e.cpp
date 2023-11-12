#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int parent[212345];
int sz[212345];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) make_set(i);

    int ans = 0;
    bool exists[212345];
    vector<int> rec;
    for(int i = n-1; i > 0; --i){
        ans++;
        exists[i] = true;
        for(auto v : g[i]){
            if(exists[v]){
                if(find_set(v) != find_set(i)){
                    union_sets(v, i);
                    ans--;
                }
            }
        }
        rec.push_back(ans);
    }

    for(int i = rec.size()-1; i >= 0; --i){
        cout << rec[i] << endl;
    }
    cout << 0 << endl;

}