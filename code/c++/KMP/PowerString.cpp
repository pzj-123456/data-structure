#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e6 + 10;

int Next[N];
char ch[N];

void getNext(int len) {
    int i = 0, j = -1;
    Next[0] = -1;

    while(i < len) {
        if(j == -1 || ch[i] == ch[j]) Next[++i] = ++j;
        else j = Next[j];
    }
}

int main() {
    while(scanf("%s", &ch), ch[0] != '.') {
        int len = strlen(ch);
        getNext(len);

        int ans;
        if(len % (len - Next[len]) == 0) 
            ans = len / (len - Next[len]);
        else ans = 1;
        printf("%d\n", ans);
    }

    return 0;
}