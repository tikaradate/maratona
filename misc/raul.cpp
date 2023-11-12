#include <bits/stdc++.h>
using namespace std;
vector<int> v, v2;
vector<int> ps;

void check(size_t n) {
  set<int> todos, todos2;
  for (int i : v) todos.insert(i);
  for (int i : v2) todos2.insert(i);
  cout << todos.size() << '\n';
  // assert(todos.size() == n);
  // assert(todos2.size() == n);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  v.resize(n);
  ps.resize(n);
  for (auto &i : v) cin >> i;
  check(n);
  return 0;
  ps[0] = 1;
  for (int i = 1; i < n; ++i)
    ps[i] = ps[i-1] + (v[i] > v[i-1]);
  bool ok = false;
  for (int i = k; i < n; ++i)
    ok |= ps[i] - ps[i-k] == k;
  if (!ok) {
    // n-k-1 é o meio
    int mid = n-k-1;
    int l;
    for (l = 1; mid-l+1 && v[mid-l] < v[mid-l+1]; ++l);
    l--;
    auto v2 = v;
    assert(mid-l >= 0);
    assert(mid-l+k <= n);
    assert(mid+1 >= 0);
    assert(mid+1+k <= n);
    sort(v.begin()+mid-l, v.begin()+mid-l+k);
    sort(v2.begin()+mid+1, v2.begin()+mid+1+k);
    bool fi;
    for (int i = mid-l; i < n; ++i)
      if ((fi = v[i] > v2[i]) || (v2[i] > v[i]))
        break;
    // check(n);
    if (!fi)
      v = v2;
  }
  for (int i = 0; i < n; ++i)
    cout << v[i] << ' ';
  cout << '\n';
}