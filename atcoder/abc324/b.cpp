#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long a;
    cin >> a;
    if(a%2 == 0)
        do { a = a/2; }while(a %2LL == 0) ;
    if(a%3 == 0)
       do {  a = a/3; } while(a%3LL == 0);
    if(a == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}