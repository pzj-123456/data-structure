#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1010;
int sg[N], n;

void getSG(int x){
    set<int> st;
    for(int i = 1; i <= x; i *= 2){
        st.insert(sg[x - i]);
    }
    for(int i = 0; i < 1000; i ++){
        if(!st.count(i)){
            sg[x] = i; return;
        }
    }
}

void solve(){
    memset(sg, -1, sizeof sg);
    for(int i = 0; i <= 1000; i ++){
        getSG(i);
    }
    while(cin >> n){
        if(sg[n]) cout << "Kiki\n";
        else cout << "Cici\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}