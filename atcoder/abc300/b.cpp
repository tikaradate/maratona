#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int h, w;

bool check_eq(vector<string> &a, vector<string> &b, int sh, int sw){
    bool eq = true;
    for(int i = sh; i < h+sh; ++i)
        for(int j = sw; j < w+sw; ++j){
            // cout << i%h << ' ' << j%w << endl;
            if(a[i%h][j%w] != b[i-sh][j-sw]){
                eq = false;
                break;
            }
        }
    return eq;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> h >> w;
    vector<string> a(h);
    vector<string> b(h);
    for(int i = 0; i < h; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < h; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(check_eq(a, b, i, j)){ cout << "Yes" << endl; return 0;}
        }
    }
    cout << "No" << endl;
}