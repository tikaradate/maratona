#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using vi = vector<int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vi f(m);
    for(int i = 0; i < m; ++i) cin >> f[i];

    int f_i = 0;
    for(int i = 1; i <= n; ++i){
        int dif = f[f_i] - i;
        cout << dif << endl;
        if(dif == 0) f_i++;
    }
}