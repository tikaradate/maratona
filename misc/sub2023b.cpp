#include <bits/stdc++.h>

using namespace std;

bool used[1123456];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    // if(sorted(v[i])){
    //     cout << 0 << endl;
    //     return 0;
    // }

    vector<int> lis;
    for (int i = 0; i < v.size(); i++) {
        auto it= lower_bound(lis.begin(), lis.end(), v[i]);
        if (it == lis.end()) {
            lis.push_back(v[i]);
        }
        else {
            *it = v[i];
        }
    }

    for(int i = 0; i < lis.size(); ++i){
        used[lis[i]] = true;
        cout << lis[i] << ' ';
    }
    cout << endl;

    vector<int> left;
    for(int i = 0; i < n; ++i){
        if(!used[v[i]]) left.push_back(v[i]);
    }

    for(int i = 0; i < left.size(); ++i){
        cout << left[i] << ' ';
    }
    cout << endl;

    // Create an empty set and insert first element in it
    multiset<int> set1;
    set1.insert(left[0]);
  
    int invcount = 0; // Initialize result
  
    multiset<int>::iterator itset1; // Iterator for the set
  
    // Traverse all elements starting from second
    for (int i=1; i<n; i++)
    {
        // Insert left[i] in set (Note that set maintains
        // sorted order)
        set1.insert(left[i]);
  
        // Set the iterator to first greater element than left[i]
        // in set (Note that set stores left[0],.., left[i-1]
        itset1 = set1.upper_bound(left[i]);
  
        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of left[i]
        int invs = distance(itset1, set1.end());
        invcount = max(invcount, invs);
    }


    cout << invcount << endl;
}

