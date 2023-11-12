#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = double;
using ii = pair<int, int>;
const ld eps = 1e-9;
const ld PI = acos(-1);
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int r, s, h;
  cin >> r >> s >> h;
  ld num = (2.*PI*r)/(double(s)*h);
  ld new_num = (int)(num+.5);
  int s1, s2, s3;
  if (num - new_num > eps) {
    s1 = 1; s2 = -1; s3 = 1;
  } else {
    s1 = -1; s2 = 1; s3 = -1;
  }
  ld best = 1e15, diff = fabsl(num-best);
  int a1, a2, a3;
  const int VALOR = 1200;
  // auto f = [&](int n1, int n2, int n3) { }
  for (int n1 = 2; n1 < VALOR; ++n1)
    for (int n2 = n1+n1; n2 < VALOR; n2 += n1)
      for (int n3 = n2+n2; n3 < VALOR; n3 += n2) {
        ld tentativa = new_num + (1./(s1*n1) + 1./(s2*n2) + 1./(s3*n3));
        if (diff > fabsl(num - tentativa)) {
          diff = fabsl(num - tentativa);
          best = tentativa;
          a1 = n1;
          a2 = n2;
          a3 = n3;
        }
      }
  cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
  // cout << "erro=" << num-best << '\n';
}
 