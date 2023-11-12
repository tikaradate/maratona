#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using iii = tuple<int, int, int>;

bool used[112345];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<iii> a(n);
    for(int i = 0; i < n; ++i){
        int d, p;
        cin >> d >> p;
        a[i] = {d, p, i+1};
    }

    sort(a.rbegin(), a.rend());

    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(!used[get<0>(a[i])]){
            ans.push_back(get<2>(a[i]));
            used[get<0>(a[i])] = true;
        }
    }

    cout << ans.size() << endl;
    for(int i = ans.size()-1; i >= 0; --i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}