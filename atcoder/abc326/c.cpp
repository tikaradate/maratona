#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map<int, int> a;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        a[x]++;
    }
    auto i = a.begin();
    auto j = a.begin();
    int ans = 0, cur = 0;
    while(j != a.end()){
        if(j->first - i->first < m){
            cur += j->second;
            j++;
        } else {
            cur -= i->second;
            i++;
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;

}