#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int m[101][101];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while(n != 0){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> m[i][j];
            }
        }
        int ps[101][101];
        for(int i = 0; i < n; ++i){
            ps[i][0] = 0;
            for(int j = 1; j <= n; ++j){
                ps[i][j] = ps[i][j-1] + m[i][j-1];
                // cout << ps[i][j] << ' ';
            }
            // cout <<endl;
        }
        int mx = 0;
        for(int i = 3; i <= n; i += 2){
            for(int j = 0; j <= n-i; ++j)
            for(int k = 0; k <= n-i; ++k){
                int can = true;
                int b = 0;
                // cout << endl;
                for(int u = 0; u < i; ++u){
                    // segunda metade do quadrado, número de espaços em preto aumenta
                    if(u > i/2){
                        b += 2;
                    } else {
                    // primeira metade do quadrado, número de espaços em preto é dada por essa expressão
                        b = i - (2*u + 1);
                    }
                    int w = i - b;

                    int s1, s2, s3;
                    s1 = (ps[j+u][k+b/2] - ps[j+u][k]);
                    s2 = (ps[j+u][k+b/2+w] - ps[j+u][k+b/2]);
                    s3 = (ps[j+u][k+b+w] - ps[j+u][k+b/2+w]);
                    // cout << j << ' ' << k << ' ' << b << endl;
                    // cout << ps[j][k+b/2] << endl;
                    // cout << b << ' ' << w << endl;
                    // cout << s1 << ' ' << s2 << ' ' << s3 << endl;
                    can &= !((s1 != b/2) || (s2 != 0) || (s3 != b/2));
                    // for(int v = 0; v < i; ++v){
                    //     if(v < i/2 - w/2 || v > i/2 + w/2){
                    //         can &= m[u+j][v+k] == 1;
                    //     } else {
                    //         can &= m[u+j][v+k] == 0;
                    //     }
                    // }
                }
                // cout << can << endl;
                if(can) mx = i;
                // cout << endl;   
            }
        }
        if(mx == 0) cout << "No solution" << endl;
        else cout << mx << endl;
        cin >> n;
    }
}