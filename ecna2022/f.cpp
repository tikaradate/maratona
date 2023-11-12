#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;


int main(){
    double r, s, h; cin >> r >> s >> h;
    double days = 2.0*r*acos(-1)/(s*h);
    double round_days = round(days);
    bool up = (round_days > days);
    double diff = 11234567;
    int a1, a2, a3;
    for(int n1 = 2; n1 <= 1000; ++n1){
        for(int n2 = 2*n1; n2 <= 2000; n2 += n1){
            for(int n3 = 2*n2; n3 <= 3000; n3 += n2){
                double curr;
                if(!up){
                    curr = round_days + 1./n1 - 1./n2 + 1./n3;
                } else {
                    curr = round_days - 1./n1 + 1./n2 - 1./n3;
                }
                if(diff > abs(days - curr)){
                    diff = abs(days - curr);
                    a1 = n1;
                    a2 = n2;
                    a3 = n3;
                }
            }
        }
    }

    cout << a1 << ' ' << a2 << ' ' << a3 << endl;
}