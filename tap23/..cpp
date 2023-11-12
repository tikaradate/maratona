#include <bits/stdc++.h>

using ll = long long;
#define endl '\n'

int main(){
    cin_tie(0)->sync_with_stdio(false);
    int a1, a2, p1, p2;
    cin >> a1 >> p1;
    cin >> a2 >> p2;
    if(a1 + a2 > p1 + p2) cout << "A" << endl;
    else if (a1 + a2 > p1 + p2) cout << "P" << endl;
    else cout << "D" << endl;
}