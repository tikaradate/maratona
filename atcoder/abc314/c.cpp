#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<char>> sort_color(m);
    vector<int> sort_color_pointer(m, 0);

    vector<int> pair_color(n);

    for(int i = 0; i < n; ++i){
        int c; cin >> c;
        c--;
        sort_color[c].push_back(s[i]);
        pair_color[i] = c;
    }

    for(int i = 0; i < n; ++i){
        // int cur_color = pair_color[i];
        int sz = sort_color[pair_color[i]].size();
        // cout << sz << endl;
        // cout << (sort_color_pointer[pair_color[i]]+sz-1)%sz << ' ';
        // fflush(stdout);
        cout << sort_color[pair_color[i]][(sort_color_pointer[pair_color[i]]+sz-1)%sz];
        sort_color_pointer[pair_color[i]]++;
    }
    cout << endl;
}