#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int M = 1e4 + 10;
const int N = 1e6 + 10; 

int Next[M];
char ch[M], s[N];

void getNext(int len) {
    Next[0] = -1;
    int i = 0, j = -1;
    
    while(i < len) {
        if(j == -1 || ch[i] == ch[j]) Next[++i] = ++j;
        else j = Next[j];
    }
    // for(int i = 0; i <= len; i++)
    //     cout << Next[i] << ' ';
    // cout << endl;
}

int main() {
    int T; scanf("%d", &T);

    while(T--) {
        scanf("%s\n%s", &ch, &s);
        getNext(strlen(ch));
        
        int len = strlen(s), i = 0, j = 0;
        int cnt = 0, len2 = strlen(ch);
        while(i < len) {
            if(j == -1 || s[i] == ch[j]) i++, j++;
            else j = Next[j];

            if(j == len2) cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}