#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define int __int128_t
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;

template<class T> using ordered_multiset = tree<T, null_type , less_equal<T> , rb_tree_tag , tree_order_statistics_node_update>;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef tuple<int, int, int> iii;
typedef vector<int> vi; 
const ll oo = 1987654321987654321;

template<class It> void db(It b, It e) {
    for (auto it = b; it != e; it++) cout << *it << ' ';
    cout<< endl;
}

// 128 Bit Integers
// cout, cerr, etc; may over/underflow
ostream& operator<<(ostream& out, __int128 x) {
    if (x == 0) return out << 0;
    string s; bool sig = x < 0; x = x < 0 ? -x : x;
    while(x > 0) s += x % 10 + '0', x /= 10;
    if (sig) s += '-';
    reverse(all(s));
    return out << s;
}
// cin, etc; may over/underflow
istream& operator>>(istream& in, __int128& x) {
    char c, neg = 0; while(isspace(c = in.get()));
    if(!isdigit(c)) neg = (c == '-'), x = 0;
    else x = c - '0';
    while(isdigit(c = in.get())) x = (x << 3) + (x << 1) - '0' + c;
    x = neg ? -x : x; return in;
}

int _sqrt(int x) {

  int l = 0, r = 1; //l² < x <= r²
  while (r * r < x) r *= 2;
  while (r - l > 1) {
    int m = l + (r-l)/2;
    if (m * m >= x) r = m;
    else l = m;
  }
  return r;
}

ii bhaskara(int a, int b, int c){
    int delta = b * b - 4 * a * c;
    if (delta < 0){
        return {-1, -1};
    }
    int tmp = _sqrt(delta);
    if (tmp * tmp != delta){
        return {-1, -1};
    }
    int r1 = (-b + tmp);
    int r2 = (-b - tmp);

    if (r1 % (2 * a) == 0){
        r1 = r1 / (2 * a);
    }else{
        r1 = -1;
    }
    if (r2 % (2 * a) == 0){
        r2 = r2 / (2 * a);
    }else{
        r2 = -1;
    }
    return {r1, r2};
}

bool valid(int r, int b, int s, int R){
    auto [r1, r2] = bhaskara(r, 2* b - r, - 2 * s);
    int retval = 0;
    if (r1 != -1 &&
        b * r1 <= R){
        retval++;
    }
    if (r2 != -1 &&
        b * r2 <= R){
        retval++;
    }
    return retval > 0;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    int A, S, L, R;
    cin >> A >> S >> L >> R;
    int ans = 0;
    for (int r=1; r <= (R - L + 1); r++){
        for (int b=A; b >= L; b -= r){
            if (valid(r, b, S, R)){
                ans++;
            }
        }
    }
    cout << ans << "\n";

}
