#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lili = pair<ll, ll>;
#define fi first
#define se second

int main(){
    int n; cin >> n;
    vector<string> names(n);
    vector<ll> ages(n);
    ll max_age = 2123456789;
    int max_idx = -1;
    for(int i = 0; i < n; ++i){
        string name; ll age;
        cin >> name >> age;
        names[i] = name;
        ages[i] = age;
        if(age < max_age){
            max_age = age;
            max_idx = i;
        }
    }

    for(int i = 0; i < n; ++i){
        cout << names[(i+max_idx)%n] << endl;
    }
}