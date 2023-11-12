#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[(n-1)/2] << ' ' << y[(n-1)/2] << endl;

}