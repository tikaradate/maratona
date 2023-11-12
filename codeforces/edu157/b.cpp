#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; ++ i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<int> x(n);
        vector<int> y(n);
        int x_sum = 0;
        int y_sum = 0;
        for(int i = 0; i < n; i++){
            x[i] = a[i];
            y[i] = a[i+n];
            if(i > 0){
                x_sum += abs(x[i-1] - x[i]);
                y_sum += abs(y[i-1] - y[i]);
            }
        }

        cout << x_sum + y_sum << endl;
        for(int i = 0; i < n; i++){
            cout << x[i] << ' ' << y[i] << endl;
        }
    }
}