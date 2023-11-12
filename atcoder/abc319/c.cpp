#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    int m[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> m[i][j];
        }
    }
    vector<ii> pos = {
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {2, 2}
    };
    
    double ok = 0, n_ok = 0;
    do{
        int m1[3][3];
        int j = -1;
        for(int i = 0; i < 9; ++i){
            if(i%3 == 0) j++;
            m1[j][i%3] = m[pos[i].first][pos[i].second];
        }

        bool broke = false;
        for(int i = 0; i < 3; ++i){
            if((m1[i][0] == m1[i][1]) && (m1[i][1] != m1[i][2])) broke = true; // linha
            if((m1[0][i] == m1[1][i]) && (m1[1][i] != m1[2][i])) broke = true; // coluna
        }
        if((m1[0][0] == m1[1][1]) && (m1[1][1] != m1[2][2])) broke = true; // diag principal
        if((m1[2][0] == m1[1][1]) && (m1[1][1] != m1[0][2])) broke = true; // diag secundaria

        if(broke) n_ok++;
        else ok++;
    }while(next_permutation(pos.begin(), pos.end()));

    cout << n_ok << ' ' << ok << endl;
    cout << (1.0 - ((double)n_ok/362880.0)) << endl;
}