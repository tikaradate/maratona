#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> divs(10, 0);
    for(int i = 1; i <= 9; ++i){
        if(n%i == 0) divs[i] = 1;
    }
    for(int i = 0; i <= n; ++i){
        int mn = 1123456789;
        for(int j = 0; j < 11; ++j){
            if(divs[j] == 1){
                if(i % (n/j) == 0) mn = min(j, mn);
            }
        }
        if(mn == 1123456789) cout << '-';
        else cout << mn;
    }
    cout <<endl;
}