#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

int n,m;
int a[210][210],p[210];
bool vis[210];
int col[210];
bool match(int i) {
    for(int j = 1;j <= n;j ++) {
        if(a[i][j] && !vis[j]) {
            vis[j] = 1;
            if(!p[j] || match(p[j])) {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}
bool chk(int u,int c){// 从这个点开始是否能够染色为二分图
    col[u] = c;
    for(int i = 1;i <= n;i ++) {
        if(a[u][i]) {
            if(col[i] == col[u]) return false;
            if(!col[i] && !chk(i,3 - c)) return false;
        }
    }
    return true;
}