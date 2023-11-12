#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void rotate90Clockwise(vector<string> &a, int N){
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    vector<string> m(1000);
    while(t--){
        int n; cin >> n;
        
        for(int i = 0; i < n; ++i){
            cin >> m[i];
        }
        vector<vector<int>> l(n*n);
        
        for(int r = 0; r < 4; r++){
            int c = 0;
            for(int i = 0; i < n/2; ++i){
                for(int j = 0; j < n/2; ++j){
                    l[c++].push_back(m[i][j]);
                    // cout << m[i][j];
                }
                // cout << endl;
            }
            // cout << endl;
            rotate90Clockwise(m, n);
            // for(int i = 0; i < n; ++i){
            //     for(int j = 0; j < n; ++j){
            //         cout << m[i][j] << ' ';
            //     }
            // cout << endl;
            // }
            // cout << endl;
        }

        ll ans = 0;
        for(int i = 0; i < l.size(); ++i){
            int m = 0;
            // for(int j = 0; j < l[i].size(); ++j){
            //     cout << l[i][j] << ' ';
            // }
            // cout << endl;
            for(int j = 0; j < l[i].size(); ++j){
                m = max(m, l[i][j]);
            }
            for(int j = 0; j < l[i].size(); ++j){
                ans += m - l[i][j];
            }
        }
        cout << ans << endl;
    }
}

