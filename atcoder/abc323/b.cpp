#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> m(n);
    for(int i = 0; i < n; ++i){
        cin >> m[i];
    }

    vector<pair<int, int>> p(n);
    tuple<int, int, int> t;

    for(int i = 0; i < n; ++i){
        p[i].first = 0;
        p[i].second = -(i+1);
        for(int j = 0; j < n; ++j){
            if(m[i][j] == 'o') p[i].first++; 
        }
    }

    sort(p.begin(), p.end());
    for(int i = n-1; i >= 0; --i){
        cout << -p[i].second << ' ';
    }

    cout << endl;
}