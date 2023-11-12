#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, x; cin >> n >> x;
    vector<int> a(n-1);
    int mx = 0, mn = 112345678;
    int s = 0;
    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        s += a[i];
    }
    int ans = x - (s - mx - mn);
    if(mx < ans) cout << - 1 << endl;
    else if(ans <= mn) cout << 0 << endl;
    else cout << ans << endl;
}