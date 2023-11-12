#include <bits/stdc++.h>

#define MAX 512
using namespace std;

vector<vector<int>> g(MAX, vector<int>());
int n, m;
vector<int> Blossom(vector<vector<int>>& g) {
  int n = g.size(), timer = -1;
  vector<int> mate(n, -1), label(n), parent(n), 
              orig(n), aux(n, -1), q;
  auto lca = [&](int x, int y) {
    for (timer++; ; swap(x, y)) {
      if (x == -1) continue;
      if (aux[x] == timer) return x;
      aux[x] = timer;
      x = (mate[x] == -1 ? -1 : orig[parent[mate[x]]]);
    }
  };
  auto blossom = [&](int v, int w, int a) {
    while (orig[v] != a) {
      parent[v] = w; w = mate[v];
      if (label[w] == 1) label[w] = 0, q.push_back(w);
      orig[v] = orig[w] = a; v = parent[w];
    }
  };
  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v], nv = mate[pv];
      mate[v] = pv; mate[pv] = v; v = nv;
    }
  };
  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    q.clear(); 
    label[root] = 0; q.push_back(root);
    for (int i = 0; i < (int)q.size(); ++i) {
      int v = q[i];
      for (auto x : g[v]) {
        if (label[x] == -1) {
          label[x] = 1; parent[x] = v;
          if (mate[x] == -1) 
            return augment(x), 1;
          label[mate[x]] = 0; q.push_back(mate[x]);
        } else if (label[x] == 0 && orig[v] != orig[x]) {
          int a = lca(orig[v], orig[x]);
          blossom(x, v, a); blossom(v, x, a);
        }
      }
    }
    return 0;
  };
  // Time halves if you start with (any) maximal matching.
  for (int i = 0; i < n; i++) 
    if (mate[i] == -1) 
      bfs(i);
  return mate;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans = Blossom(g);
    int c = 0;
    for(int i = 0; i < n; ++i){
        if(ans[i] != -1) c++;
    }
    cout << c/2 << endl;
    vector<bool> used(n, false);
    for(int i = 0; i < n; ++i){
        if(ans[i] != -1 && !used[i]){
            cout << i << ' ' << ans[i] << endl;
            used[i] = true;
            used[ans[i]] = true;
        }
    }
}