#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    char a[112][112];

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n-8; ++i){
    for(int j = 1; j <= m-8; ++j){
        bool can = true;
        for(int k = 0; k < 9; ++k){
        for(int l = 0; l < 9; ++l){
            // cout << a[i+k][j+l];
            if(k < 3 && l < 3){
                if(a[i+k][j+l] != '#') can = false;
            } else if(k >= 6 && l >= 6){
                if(a[i+k][j+l] != '#') can = false;
            } else if(k == 3 && l <= 3){
                if(a[i+k][j+l] != '.') can = false;
            } else if(k <= 3 && l == 3){
                if(a[i+k][j+l] != '.') can = false;
            } else if(k == 5 && l >= 5){
                if(a[i+k][j+l] != '.') can = false;
            } else if(k >= 5 && l == 5){
                if(a[i+k][j+l] != '.') can = false;
            }
            // cout << can ;
            // if(!can)break;
        }
        // cout << endl;
        }
        if(can) cout << i << ' ' << j << endl;
        // else break;
        // cout << endl;
        // break;
    }
    // break;
    }
}