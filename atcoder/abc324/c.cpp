#include <bits/stdc++.h>

using namespace std;

int levenshteinDist(string word1, string word2) {
    int size1 = word1.size();
    int size2 = word2.size();
    int verif[size1 + 1][size2 + 1];

    if (size1 == 0)
        return size2;
    if (size2 == 0)
        return size1;

    for (int i = 0; i <= size1; i++)
        verif[i][0] = i;
    for (int j = 0; j <= size2; j++)
        verif[0][j] = j;
        cout << endl;
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            int cost = (word2[j - 1] == word1[i - 1]) ? 0 : 1;

            verif[i][j] = min(
                min(verif[i - 1][j] + 1, verif[i][j - 1] + 1),
                verif[i - 1][j - 1] + cost
            );
            cout << verif[i][j] << ' ';
            // if(verif[i][j] > 1) return 2;
        }
        cout << endl;
    }

    return verif[size1][size2];
}

int levenshteinDistHelp(string s, string t){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string t; cin >> t;
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        if(levenshteinDistHelp(s, t) <= 1 ) ans.push_back(i+1); 
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
}