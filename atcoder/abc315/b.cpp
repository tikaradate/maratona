#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;

    cin >> n;
    vector<int> days_of_month(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        sum += a;
        days_of_month[i] = a;
    }

    int middle = (sum + 1 )/2;
    sum = 0;
    for(int i = 0; i < n; ++i){
        if(sum + days_of_month[i] >= middle){
            cout << i + 1 << ' ';
            cout << middle - sum << endl;
            break;
        } else {
            sum += days_of_month[i];
        }
    }
}