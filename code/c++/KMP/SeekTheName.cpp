#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int N = 4e5 + 10;

int Next[N], ans[N], cnt;
char s[N];


void getNext() {
    Next[0] = -1;
    int i = 0, j = -1;
    int len = strlen(s);
    while(i < len) {
        if(j == -1 || s[i] == s[j]) Next[++i] = ++j;
        else j = Next[j]; 
    }
}

int main() {
    while(scanf("%s", &s) != EOF) {
        getNext();
        cnt = 0;
        int j = strlen(s);
        while(j != 0) {
            ans[cnt++] = j;
            j = Next[j];
        }
        for(int i = cnt - 1; i > 0; i--)
            printf("%d ", ans[i]);
        printf("%d \n", strlen(s));
    }

    return 0;
}