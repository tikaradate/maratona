#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    string r, c;
    cin >> r >> c;

    char m[5][5];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            m[i][j] = '*';
        }
    }

    int _a, _b, _c;
    _a = _b = _c = 0;
    bool can = true;
    // if(r[0] != c[0]) can = false;
    for(int i = 0; i < n; ++i){
        if(r[i] == 'A'){
            for(int j = 0; j < _a; ++j){
                m[i][j] = '.';
            }
            m[i][_a++] = 'A';
        }
        if(r[i] == 'B'){
            for(int j = 0; j < _b; ++j){
                m[i][j] = '.';
            }
            m[i][_b++] = 'B';
        }
        if(r[i] == 'C'){
            for(int j = 0; j < _c; ++j){
                m[i][j] = '.';
            }
            m[i][_c++] = 'C';
        }
    }
    _a = _b = _c = 0;
    for(int i = 0; i < n; ++i){
        if(c[i] == 'A'){
            for(int j = 0; j < _a; ++j){
                if(m[j][i] != '*'){
                    if(m[j][i] != '.'){
                        can = false;
                    }
                }
                m[j][i] = '.';
            }
            if(m[_a][i] != '*'){
                if(m[_a][i] != 'A'){
                    can = false;
                }
            }
            m[_a++][i] = 'A';
        }
        if(c[i] == 'B'){
            for(int j = 0; j < _b; ++j){
                if(m[j][i] != '*'){
                    if(m[j][i] != '.'){
                    can = false;
                    }
                }
                m[j][i] = '.';
            }
            if(m[_b][i] != '*'){
                if(m[_b][i] != 'B'){
                    can = false;
                }
            }
            m[_b++][i] = 'B';
        }
        if(c[i] == 'C'){
            for(int j = 0; j < _c; ++j){
                if(m[j][i] != '*'){
                    if(m[j][i] != '.'){
                    can = false;
                    }
                }
                m[j][i] = '.';
            }
            if(m[_c][i] != '*'){
                if(m[_c][i] != 'C'){
                    can = false;
                }
            }
            m[_c++][i] = 'C';
        }
    }

    for(int i = 0; i < n; ++i){
        _a = _b = _c = 0;
        for(int j = 0; j < n; ++j){
            a_ += m[i][j] == 'A';
            b_ += m[i][j] == 'B';
            c_ += m[i][j] == 'C';
        }
        if(_a == _b && _b == _c && _c == 0) continue;

        for(int j = 0; j < n; ++j){
            if(m[i][j] == 0){
                
            }
        }

    }

    if(can){
        cout << "Yes" << endl;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << m[i][j];
        //     }
        //     cout << endl;
        // }
    } else {
        cout << "No" << endl;
    }
}