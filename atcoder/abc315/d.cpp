#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    map<int, map<char, int>> line, column;
    // vector<int> nr_c_line(n, m), nr_c_column(m, n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
            line[i][grid[i][j]]++;
            column[j][grid[i][j]]++;
        }
    }
    int ans = 0;
    vector<bool> ignore_line(n), ignore_column(m);
    int nr_colum
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(line[i][grid[i][j]] == )
        }
    }
    cout << ans << endl;
}