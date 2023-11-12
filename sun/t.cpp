#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    set <int> nums;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        nums.insert(x);
    }

    for(auto it = nums.begin(); it != nums.end(); ++it){
        cout << *it << endl;
    }
}