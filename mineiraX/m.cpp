#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lili = pair<ll, ll>;

#define fi first
#define se second

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    double r; cin >> r;

    double pi = acos(-1);
    // cout << pi << endl;
    // alfa é o angulo entre a hipotenusa e o lado 2R
    double alfa = asin(3.0/5.0);
    // cout << alfa << endl;
    double height = sin(2*alfa)*r;
    // cout << height << endl;
    double left_tri = height*r/2.0;
    // cout << left_tri << endl;
    /*
        PI - (PI*r^2)/2
        ang - x

        x = (ang*(PI*r^2)/2.0)/180
    */
    double right_sector = r*r*(2*alfa)/2.0;
    // cout << right_sector << endl;

    cout << fixed << setprecision(12) << left_tri + right_sector << endl;
}