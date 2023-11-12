#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    // cout << month << endl;
    if(month < 9) cout << "GOOD" << endl;
    else if(month == 9 && day <= 16){
        cout << "GOOD" << endl;
    } else {
        cout << "TOO LATE" << endl;
    }
}