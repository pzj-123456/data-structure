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

// 1010 >> 1   101 & 1
// 10 & 01 = 0
// 0000000001100 
// 0000000000100
void insert(int x){
	int p = 0;
	for(int i = 31; i >= 0; i --){
		int t = (x >> i) & 1;
		if(!tr[p][t]) tr[p][t] = ++ idx;
		p = tr[p][t];
	}
}
// 查询trie里和x异或值最大
// 1 ^ 0 = 1, 1 ^ 1 = 0, 0 ^ 0 = 0
int query(int x){
	int p = 0, res = 0;
	for(int i = 31; i >= 0; i --){
		int t = (x >> i) & 1;
		if(tr[p][!t]) p = tr[p][!t], res += (1 << i);
		else p = tr[p][t];
	}
	return res;
}

void solve(){
	int n; cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i ++){
		int x; insert(x);
		a.push_back(x);
	}
	int ans = 0;
	for(int i = 0;  i < n; i ++){
		ans = max(ans, query(a[i]));
	}
	cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}