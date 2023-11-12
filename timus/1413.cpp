#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const double diag = 0.70710678118654752440084436210485;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    double x = 0.f, y = 0.f;
    // 1 2 3 4 5 6 7 8 9
    vector<pair<double, double>> d = {
        {-diag, -diag}, {0.0, -1.0}, {diag, -diag},
        {-1.0, 0.0}, {0.0, 0.0}, {1.0, 0.0},
        {-diag, diag}, {0.0, 1.0}, {diag, diag},
    };
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '0') break;
        x += d[s[i]-'0'-1].first;      
        y += d[s[i]-'0'-1].second;      
    }
    
    cout << setprecision(10) << fixed << x << ' ' << y << endl;
}