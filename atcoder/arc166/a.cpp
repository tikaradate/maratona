#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        // cout << "case " << t << endl;
        int n;
        string x, y;
        cin >> n >> x >> y;
        vector<int> c_idx;
        c_idx.push_back(0);
        for(int i = 0; i < n; ++ i){
            if(y[i] == 'C' && x[i] == 'C') c_idx.push_back(i-1);
        }
        c_idx.push_back(n-1);
        int i = 0;
        bool can = true;
        do{
            int off = i > 0 ? 2 : 0;
            int sz = c_idx[i+1] - c_idx[i] + 1 - off;
            string s_x = x.substr(c_idx[i]+off, sz);
            string s_y = y.substr(c_idx[i]+off, sz);
            int x_a, x_b, x_c, y_a, y_b, y_c;
            x_a = x_b = x_c = y_a = y_b = y_c = 0;
            for(int j = 0; j < sz; j++){
                if(s_x[j] == 'A') x_a++;
                if(s_x[j] == 'B') x_b++;
                if(s_x[j] == 'C') x_c++;
                if(s_y[j] == 'A') y_a++;
                if(s_y[j] == 'B') y_b++;
                if(s_y[j] == 'C') y_c++;
            }

            int t_c = x_c - y_c;
            int t_a = x_a - y_a;
            int t_b = x_b - y_b;
            // cout << s_x << ' ' << s_y << endl;
            // cout << t_a << ' ' << t_b << ' ' << t_c << endl;
            if(t_a + t_b + t_c != 0 || t_c < 0){
                can = false;
            }
            if((s_x[0] == 'B') && (s_y[0] == 'A')){
                can = false;
            }
            if((s_x[sz-1] == 'A') && (s_y[sz-1] == 'B')){
                can = false;
            }
            i++;
        } while(i < c_idx.size()-1 && can);
        
        if(can) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}