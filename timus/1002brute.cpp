#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    int s = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int min_diff = 1123456789;
    for (int m = 0; m < (1<<n); m++){
        int p1 = 0, p2 = 0;
        for(int i = 0; i < n; ++i){
            if(m & 1 << i) p1 += v[i];
            else p2 += v[i];
        }
        min_diff = min(min_diff, abs(p1 - p2));
    }

    cout << min_diff << endl;
}