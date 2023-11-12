#include <bits/stdc++.h>

using namespace std;

string removeOccurrences(string a, string b) {
    int nb = b.size(), na = a.size();
    vector<int> kmp(nb + 1), idx(na + 1), st;
    for (int i = 1; i < nb; i++) {
        int j = kmp[i - 1];
        while (j && b[i] != b[j]) j = kmp[j - 1];
        if (b[i] == b[j]) 
            ++j;
        kmp[i] = j;
    }
    int d = 0, j = 0;
    for (int i = 0; i < na; i++) {
        a[i - d] = a[i];
        while (j && a[i - d] != b[j]) j = kmp[j - 1];
        if (a[i - d] == b[j]) ++j;
        idx[i - d] = j;
        if (j == nb) {
            d += nb;
            j = i >= d ? idx[i - d] : 0;
        }
            
    }
    return a.substr(0, na - d);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    cout << removeOccurrences(s, "ABC") << endl;
}