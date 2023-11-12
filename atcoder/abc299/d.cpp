#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    bool found = false;
    int s = 1, f = n;
    while(!found){
        int ans;
        int m = (f+s)/2;
        cout << "? " << m << endl;
        cin >> ans;
        if(ans == 0){
            s = m;
        } else {
            f = m;
        }
        if(s == f-1){
            cout << "! " << s << endl;
            return 0;
        }
    }
}