#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> sum(n, 0);
    for(int i = 0; i < n-1; ++i){
        sum[i+1] = sum[i] + (s.substr(i, 2) == "AC" ? 1 : 0);
        // cout << s.substr(i, 2) << endl;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum[r-1] - sum[l-1] << endl; 
    }
}