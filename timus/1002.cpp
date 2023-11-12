#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int n, min_diff, p1, p2;

void dp(){
    if(i == n){
        return;
    }
    if(memo[i][j] != -1) return memo[i][j];
    min_diff = min(min_diff, p1-p2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }



    cout << min_diff << endl;
}