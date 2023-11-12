#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int h, w; 

bool cross(vector<string> &c, int s, int x, int y){
    if(x - s/2 < 0 || y - s/2 < 0 || x + s/2 >= h || y + s/2 >= w) return false;
    bool can = true;
    int inix = x - s/2;
    int iniy = y - s/2;

    // cout << "s   : " << s << endl;
    // cout << "x   : " << x << endl;
    // cout << "inix: " << inix << endl;
    // cout << "y   : " << y << endl;
    // cout << "iniy: " << iniy << endl;
    // cout << "sub " << s << endl;
    for(int i = inix; i <= x+s/2; ++i){
        for(int j = iniy; j <= y+s/2; ++j){
            // cout << i << ' ' << j << " / ";
            // cout << c[i][j] << ' ' << i-inix << ' ' << j-iniy << "/";
            // cout << c[i][j] <<  " ";
            if(i - inix == j - iniy){
                if(c[i][j] != '#') can = false;
            } else if(i-inix + j - iniy == s-1){
                if(c[i][j] != '#') can = false;
            }
        }
        // cout << endl;
    }
    // if(can) cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    return can;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> h >> w;
    vector<string> c(h);
    for(int i = 0; i < h; ++i) cin >> c[i];

    int s = min(h, w);
    map<ii, bool> v;
    vector<int> ans(s, 0);
    for(int k = s; k >= 3; --k){
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(cross(c, k, i, j) && v.find({i, j}) == v.end()){ 
                    v[{i, j}] = true;
                    ans[k/2-1]++;
                }
            }
        }
    }

    for(int i = 0; i < s; ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;

}