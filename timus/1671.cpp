#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define MAX 112345

vector<int> parent(MAX), sz(MAX);

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
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; ++i){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    int q;
    cin >> q;
    vector<int> cuts(q);
    vector<bool> is_cut(m, false);
    for(int i = 0; i < q; ++i){
        cin >> cuts[i]; 
        cuts[i]--;
        is_cut[cuts[i]] = true;
    }
    reverse(all(cuts));

    for(int i = 0; i < n; ++i){
        make_set(i);
    }

    int comps = n;
    for(int i = 0; i < m; ++i){
        if(is_cut[i]){
            continue;
        }
        // cout << "joining " << edges[i].first << " and " << edges[i].second << endl;
        // cout << "ranks: " << find_set(edges[i].first) << " and " << find_set(edges[i].second) << endl;
        int u, v;
        u = find_set(edges[i].first);
        v = find_set(edges[i].second);
        if(u != v){
            union_sets(edges[i].first, edges[i].second);
            comps--;
        }

    }
    vector<int> ans;
    ans.push_back(comps);
    for(int i = 0; i < q; ++i){
        int u, v;
        // cout << "joining " << edges[cuts[i]].first << " and " << edges[cuts[i]].second << endl;
        // cout << "ranks: " << find_set(edges[cuts[i]].first) << " and " << find_set(edges[cuts[i]].second) << endl;
        u = find_set(edges[cuts[i]].first);
        v = find_set(edges[cuts[i]].second);
        if(u != v){
            union_sets(edges[cuts[i]].first, edges[cuts[i]].second);
            comps--;
        }
        ans.push_back(comps);
    }

    for(int i = ans.size()-2; i >= 0; --i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}