#include <bits/stdc++.h>

using namespace std;

using dd = pair<double, double>;

#define xx first
#define yy second

bool visited[2000];
vector<vector<int>> g(2000);

void dfs(int v){
    visited[v] = true;
    for(auto u : g[v]){
        if(!visited[u])
            dfs(u);
    }
}

int main(){
    double n, d; cin >> n >> d;
    vector<dd> pos(n);
    for(int i = 0; i < n; ++i){
        cin >> pos[i].xx >> pos[i].yy;
        
    }
    for(int i = 0; i < n; ++i){
        bool can = false;
        for(int j = i+1; j < n; ++j){
            double dist = sqrt(((pos[i].xx-pos[j].xx)*(pos[i].xx-pos[j].xx)) + ((pos[i].yy-pos[j].yy)*(pos[i].yy-pos[j].yy)));
            // cout << pos[i].xx << ' ' << pos[i].yy << " - " << pos[j].xx << ' ' << pos[j].yy << endl;
            // cout << dist << endl;
            if(dist <= d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    dfs(0);
    for(int i = 0; i < n; ++i){
        if(visited[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}