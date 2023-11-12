#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;

    FenwickTree t(n);

    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1]) t.add(i, 1);
    }

    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        l--; r--;
        // for(int j = l; j <= r; ++j) cout << s[j];
        // cout << endl;
        int sum = t.sum(l, r);
        if(l > 0 && s[l-1] == s[l]) sum--;
        cout << sum << endl;;
    }

    
}