#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int s = 0;
    for(int i = 1; i <= n; ++i){
        int d; cin >> d;
        
        for(int j = 1; j <= d; ++j){
            set<int> digs;
            int cur = j;
            int cur_m = i;
            while(cur_m != 0){
                int dig = cur_m %10;
                cur_m = cur_m/10;
                digs.insert(dig);
            }
            while(cur != 0){
                int dig = cur %10;
                cur = cur/10;
                digs.insert(dig);
            }
            
            if(digs.size() == 1) s++;
        }
    }

    cout << s << endl;
}