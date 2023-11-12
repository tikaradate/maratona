#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    
    vector<pair<int, int>> s(m);
    for(int i = 0; i < m; ++i){
        int a;
        cin >> a;
        s[i].first = a;
        s[i].second = i;
    }
    vector<string> r(n);
    for(int i = 0; i < n; ++i){
        cin >> r[i];
    }
    int max_score = 0;
    vector<int> sum_score(n);
    for(int i = 0; i < n; ++i){
        int cur_score = i+1;
        for(int j = 0; j < m; ++j){
            if(r[i][j] == 'o') cur_score += s[j].first; 
        }
        sum_score[i] = cur_score;
        max_score = max(cur_score, max_score);
    }

    sort(s.rbegin(), s.rend());
    // for(int i = 0; i < m; ++i){
    //     cout << s[i].first << ' ' << s[i].second << ' ';
    // }
    // cout << endl;
    for(int i = 0; i < n; ++i){
        int cur_score = sum_score[i];
        int qtd = 0;
        // cout << "player " << i+1 << " total: " << sum_score[i] << endl;
        for(int j = 0; j < m; ++j){
            if(cur_score < max_score){
                if(r[i][s[j].second] == 'x'){
                    // cout << "adding: " << s[j].first << endl;
                    cur_score += s[j].first;
                    qtd++;
                }
            }
        }
        cout << qtd << endl;
    }
}
