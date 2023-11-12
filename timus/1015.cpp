#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

bool used[112345];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<set<tuple<int, int, int>>> dices(n);
    for(int i = 0; i < n; ++i){
        int left, right, up, forward, down, backward;
        cin >> left >> right >> up >> forward >> down >> backward;
        vector<int> sums(3);
        sums[0] = left+right;
        sums[1] = up+down;
        sums[2] = forward+backward;
        sort(all(sums));
        dices[i].insert({sums[0], sums[1], sums[2]});
    }
    int ans_idx = 0;
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i){
        if(!used[i]){
            vector<int> same;
            same.push_back(i+1);
            for(int j = i + 1; j < n; ++j){
                if(!used[j])
                if(dices[i] == dices[j]){
                    same.push_back(j+1);
                    used[j] = true;
                }
            }
            used[i] = true;
            ans.push_back(same);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        sort(all(ans[i]));
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

}