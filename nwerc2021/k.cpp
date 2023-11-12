#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    set<string> socks;
    map<string, int> left, right, any;
    int qt_any = 0, sum_left = 0, sum_right = 0;
    for(int i = 0; i < n; ++i){
        string sock, dir;
        int qt;
        cin >> sock >> dir >> qt;
        socks.insert(sock);
        if(dir == "left"){
            sum_left += qt;
            left[sock] = qt;
        }    
        if(dir == "right"){
            sum_right += qt;
            right[sock] = qt;
        }
        if(dir == "any"){
            any[sock] = qt;
            qt_any++;
        }
    }

    int sum = 0;
    for(auto sock: socks){
        if(left[sock] <= right[sock]){
            sum += right[sock];
        } else {
            sum += left[sock];
        }
    }

    int mx = -1; string mx_sock;
    for(auto sock: socks){
        bool ok_left, ok_right, ok_any;
        ok_left = left.find(sock) != left.end() && left[sock] != 0; 
        ok_right = right.find(sock) != right.end() && right[sock] != 0; 
        ok_any = any.find(sock) != any.end(); 
        
        if(ok_left){
            if(ok_right){
                mx = max(left[sock], max(right[sock], mx));
                mx_sock = sock;
            } else if(ok_any){
                // mx = max(left[sock], max(any[sock], mx));
                mx = max(left[sock], mx);
                mx_sock = sock;
            }
        }
        if(ok_right){
            if(ok_left){
                mx = max(right[sock], max(left[sock], mx));
                mx_sock = sock;
            } else if(ok_any){
                // mx = max(right[sock], max(any[sock], mx));
                mx = max(right[sock], mx);
                mx_sock = sock;
            }
        }
        // cout << sock << ' ' << mx << ' ' << ok_left << ' ' << ok_right << ' ' << ok_any << endl;
    }

    // cout << mx << endl;
    if(mx == -1){
        for(auto [name, qt]: any){
            if(qt >= 2){
                cout << sum + 2 << endl;
                return 0;
            }
        }
        cout << "impossible" << endl;
    } else {
        int any_factor;
        if(left[mx_sock] == 0 || right[mx_sock] == 0) any_factor = 0;
        else any_factor = 1;
        // any_factor = min(min(left[mx_sock], right[mx_sock]), any[mx_sock]) > 0;
        // cout << mx_sock << endl;
        int minus = left[mx_sock] > right[mx_sock] ? left[mx_sock] : right[mx_sock];
        // cout << mx << '+' << sum << '-' << minus << '+' << qt_any << '+' << any_factor << endl;
        cout << mx + sum - minus + qt_any + (qt_any > 1 || qt_any == 1 && (any[mx_sock] == 0)) << endl;
    }

}