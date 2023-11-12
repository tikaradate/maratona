#include <bits/stdc++.h>

using namespace std;

char ans[81];

int main(){
    memset(ans, ' ', 80);
    int cursor = 0;
    while(true){
        char c = getc(stdin);
        if(c == '\n' || c == '\r' || c == EOF){
            break;
        }
        if(c == '<'){
            cursor = max(0, cursor-1);
        } else {
            if(c != '>') ans[cursor] = c;
            cursor = (cursor + 1) % 80;

        }
    }
    printf("%s", ans);
    return 0;
}