#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=200;
int g[N][N],d[N];
bool st[N];

int main()
{
    int m,n,a,b,c;
    while(cin>>n>>m, n||m) {
    memset(g,0x3f,sizeof g);
    memset(d,0x3f,sizeof d);
    memset(st,false,sizeof st);
    d[1]=0;
    for(int i=1 ;i<= m;i++) {
        cin>>a>>b>>c;
        // g[a][b]=min(c,g[a][b]);
        if(c<g[a][b]) {
            g[a][b]=g[b][a]=c;
        }
    }
    for(int i=1 ; i <= n; i++) {
        int t=d[1];
        for(int j = 1; j <= n; j++) {
            if(!st[j] && d[j] < d[t]) 
            t=j;            //find min
        }
        st[t]=1;
        for(int  j=1 ;j<=n;j++) {
            d[j] =min(d[j] , d[t] + g[t][j]);
        }
    }
    cout<<d[n]<<endl;
    }
    // system("pause");
    return 0;
}


