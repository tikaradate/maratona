#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int rt, rj; double st, sj;
    cin >> rt >> rj >> st >> sj;
    st = round(st * 100);
    sj = round(sj * 100);

    if((rt-1)*sj < (rj-1)*st) cout << "TAOYUAN" << endl;
    else if((rt-1)*sj > (rj-1)*st) cout << "JAKARTA" << endl;
    else cout << "SAME" << endl;
}