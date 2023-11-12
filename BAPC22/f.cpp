#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-15;

bool geq(double a, double b) {
    return a-b >= -eps;
}

double media(double a, double b) {
    return b+(a-b)/(double)(2.);
}

double f(string x) {
    int n = x.size();
    char start = x[n-1];
    char other = x[n-1];
    double a = 45.0;
    double change = 0;
    for(int i = n-2; i >= 0; --i){
        if(x[i] != start){
            other = x[i];
            change += a;
        } else {
            change = change - a <= 0? 0 : change - a;
        }
        a = a/2.0;
    }
    if(other == start) change = 0;
    double ans = 0;
    switch(start){
        case 'N':
            if(other == 'E'){
                ans = change;
            } else {
                ans = 360.0 - change;
            }
            break;
        case 'E':
            if(other == 'N'){
                ans = 90.0 - change;
            } else {
                ans = 90.0 + change;
            }
            break;
        case 'S':
            if(other == 'E'){
                ans = 180.0 - change;
            } else {
                ans = 180.0 + change;
            }
            break;
        case 'W':
            if(other == 'N'){
                ans = 270.0 + change;
            } else {
                ans = 270.0 - change;
            }
            break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    double fa = f(a), fb = f(b);
    if (fa < fb) swap(fa, fb);
    // cout << setprecision(33) << fixed << fa << '\n' << fb << '\n' << min(fa-fb, (360.-fa + fb)) << '\n';
    cout << setprecision(14) << min(fa-fb, (360.-fa + fb)) << '\n';
}