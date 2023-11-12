#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

long long SumOfDivisors(long long num) {
    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1) {
        total *= (1 + num);
    }
    return total;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int i, j; cin >> i >> j;
    double mn = 1123456789.0;
    int ans = -1;
    for(int k = i; k <= j; ++k){
        double n = SumOfDivisors(k);
        // cout << (n-k)/(double)k << endl;
        if(mn > (n-(double)k)/(double)k){
            ans = k;
            mn = (n-(double)k)/(double)k;
        }
    }
    cout << ans << endl;
}