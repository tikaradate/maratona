#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    string s; cin >> s;
    if(s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}