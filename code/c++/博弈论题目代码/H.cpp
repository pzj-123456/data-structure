#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1010;
int sg[N], f[1010] = {1, 1}, n, m, p;

void getSG(int x){
	set<int> st;
	for(int i = 1; i <= 20 && f[i] <= x; i ++){
		st.insert(sg[x - f[i]]);
	}
	for(int i = 0; i < 1000; i ++){
		if(!st.count(i)){
			sg[x] = i; return;
		}
	}
}

void solve(){
	for(int i = 2; i <= 20; i ++)
		f[i] = f[i - 1] + f[i - 2];
	memset(sg, -1, sizeof sg);
	for(int i = 0; i <= 1000; i ++) getSG(i);
	while(cin >> n >> m >> p && n && m && p){
		if(sg[n] ^ sg[m] ^ sg[p])
			cout << "Fibo\n";
		else cout << "Nacci\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}