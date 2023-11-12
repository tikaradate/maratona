#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int n;
  cin >> n;

  long long ans = 0;
  for(int i = 0; i < n; ++i){
    int cur_price = 0;
    string time;
    int distance;
    cin >> time >> distance;

    int hour = stoi(time.substr(0, 2));
    int rate;
    if(hour >= 22) rate = 120;
    else rate = 100;
    cur_price += b;
    if(distance > a){
      cur_price += d*((distance - a)/c + ((distance-a)%c != 0));
    }
    cur_price *= rate;
    ans += cur_price/100;
  }

  cout << ans << endl;

  return 0;
}
