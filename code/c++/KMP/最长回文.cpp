#include <iostream>
#include <string.h>
using namespace std;

const int N = 2e5 + 2e4 + 100;
char c[N];
char str[N];
int P[N];

int getLen(char s[], int n) {
    str[0] = '^';
    str[1] = '#';
    int len = 2;
    for(int i = 0; i < n; i++) {
        str[len++] = s[i];
        str[len++] = '#';
    }
    str[len++] += '$';

    memset(P, 0, sizeof P);
    int R, index, maxlen;
    R = index = maxlen = 0;
    for(int i = 1; i < len - 1; i++) {
        int j = 2 * index - i;
        P[i] = i < R ? min(P[j], R - i) : 1;
        while(str[i - P[i]] == str[i + P[i]]) P[i] ++;

        if(R < i + P[i]) {
            R = i + P[i];
            index = i;
        }
        maxlen = max(maxlen, P[i]);
    }
    return maxlen - 1;
}

int main() {

    while(~scanf("%s", &c)) {
        printf("%d\n", getLen(c, strlen(c)));
    }

    return 0;
}