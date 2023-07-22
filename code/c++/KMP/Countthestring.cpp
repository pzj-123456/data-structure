#include <iostream>
#include <string.h>
using namespace std;

const int N = 2e5 + 10;
const int mod = 10007;

int len, Next[N], sum[N];
char ch[N];

void getNext(char s[]) {
    Next[0] = -1;
    int i = 0, j = -1;

    while(i < len) {
        if(j == -1 || s[i] == s[j]) Next[++i] = ++j;
        else j = Next[j];
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        scanf("%d\n%s", &len, &ch);
        getNext(ch);
        memset(sum, 0, sizeof sum);
        int res = 0;
        for(int i = 1; i <= len; i++) {
            sum[i] = sum[Next[i]] + 1;
            res = (res + sum[i]) % mod;
        }
        cout << res << endl;
    }

    return 0;
}