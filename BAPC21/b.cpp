#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    map<string, int> att;
    for(int i = 0; i < n; ++i){
        string s; int a;
        cin >> s >> a;
        att[s] = a;
    }

    int l; cin >> l;
    vector<pair<string, int>> inp(l);
    map<string, int> ev;
    map<string, int> needs;
    map<string, int> max_pt;
    map<string, int> vis;
    for(int i = 0; i < l; ++i){
        string s; int a;
        cin >> s >> a;
        inp[i] = {s, a};
        int need = a - att[s];
        needs[s] = max(need, needs[s]);
        ev[s]++;
        max_pt[s] = max(max_pt[s], a);
        vis[s] = 0;
        // ev[s] = max(ev[s], need);
    }

    for(auto [a, b] : needs){
        // cout << a << ' ' << b << endl;
        k -= b;
        att[a] += b;
    }

    if(k <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<tuple<ll, ll, string>> points;
    // cout << endl;
    for(auto [a, b] : att){
        // cout << a << ' ' << max_pt[a] << ' ' << ev[a] << ' ' << b << endl;
        // cout << (max_pt[a]+1)*ev[a] << endl;
        if(att[a] == max_pt[a])
            points.push_back({(max_pt[a]+1)*ev[a], 0, a});
        points.push_back({ev[a], 1, a});
    }
    sort(points.rbegin(), points.rend());
    int i = 0;
    ll ans = 0;
    while(k > 0){
        auto [pt, type, st] = points[i];
        cout << pt << ' ' << type << ' ' << st << endl;
        if(type == 0){
            ans += pt;
            k--;
        } else {
            ans += (pt*k);
            k = 0;
        }
        vis[st] = 1;
        i++;
    }

    for(int i = 0; i < l; ++i){
        // cout << vis[inp[i].first] << ' ' <<  inp[i].second  << ' ' << max_pt[inp[i].first] << endl;

        if(inp[i].second != att[inp[i].first]){
            // cout << "ue" << endl;
            ans += att[inp[i].first];
        }
    }

    cout << ans << endl;
}