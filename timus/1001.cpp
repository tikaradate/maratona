#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double a;
    vector<double> ans;
    while(cin >> a){
        ans.push_back(sqrt(a));
    }

    for(int i = ans.size()-1; i >= 0; --i){
        cout << fixed << setprecision(4) << ans[i] << endl;
    }
}