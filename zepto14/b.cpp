#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> field(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> field[i][j];
        }
    }
    for(int j = 0; j < m; ++j){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(j + i + 1 <= m)
                ans += field[i][j+i] == 'L';
            if(j - i + 1 >= 0)
                ans += field[i][j-i] == 'R';
            if(i + i < n)
                ans += field[i+i][j] == 'U';            
        }
        cout << ans << ' ';
    }
    cout << endl;
}