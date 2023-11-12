#include <iostream>
#include <string>
#include <set>
using namespace std;

#define MAX 2000000000

int main(int argc, char *argv[]) {
  int n; cin >> n;

  multiset<int> test, interview;
  pair<int, int> g_test, g_interview, s_test, s_interview; 
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int type; cin >> type;
    if(type == 1){
      int a, b; cin >> a >> b;
      ans ++;
      if(ans > 1){
        if((a <= s_test.first && b <= s_interview.first)){
            ans--;
            continue;
        } else if(a > g_test.first && b > g_interview.first){
            ans--;
        } else if(a >= g_test.first){
            if(g_test.second == s_interview.second && s_interview.first <= b){
                ans--;
                s_interview.first = b;
            }
        } else if(a >= g_interview.first){
            if(s_test.second == g_interview.second && s_test.first <= a){
                ans--;
                s_test.first = a;
            }
        }
        g_test.first = max(g_test.first, a);
        g_interview.first = max(g_interview.first, b);
        s_test.first = min(s_test.first, a);
        s_interview.first = min(s_interview.first, b);
      } else {
        g_test = {a, i};
        g_interview = {b, i};
        s_test = {a, i};
        s_interview = {b, i};
      }
    } else {
      cout << ans << endl;
    }
  }
}
