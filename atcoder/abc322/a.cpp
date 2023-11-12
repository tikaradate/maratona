#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using vi = vector<int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s, abc = "ABC";
    cin >> s;
    for(int i = 0; i <= n-3; ++i){
        if(s.substr(i, 3) == abc){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}