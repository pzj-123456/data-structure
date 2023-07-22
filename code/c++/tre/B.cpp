#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1e5 + 10;
int tr[N * 32][2], idx;

void insert(int x){
	int p = 0;
	for(int i = 31; i >= 0; i --){
		int t = (x >> i) & 1;
		if(!tr[p][t]) tr[p][t] = ++ idx;
		p = tr[p][t];
	}
}

int query(int x){
	int p = 0, res = 0;
	for(int i = 31; i >= 0; i --){
		int t = (x >> i) & 1;
		if(tr[p][!t]) p = tr[p][!t], res += (!t) << i;
		else p = tr[p][t], res += t << i;
	}		
	return res;
}

void solve(){
	memset(tr, 0, sizeof tr); idx = 0;
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i ++){
		int x; cin >> x;
		insert(x);
	}
	for(int i = 0; i < m; i ++){
		int x; cin >> x;
		cout << query(x) << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int T; cin >> T;
    for(int i = 1; i <= T; i ++){
    	cout << "Case #" << i << ":\n";
    	solve();
    }
    return 0;
}