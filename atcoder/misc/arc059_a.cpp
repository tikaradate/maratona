#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];    
    }
    int ans = 1123456789;
    for(int i = -100; i <= 100; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            sum += (a[j]-i)*(a[j]-i);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}