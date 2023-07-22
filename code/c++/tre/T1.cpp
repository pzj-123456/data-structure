#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1e5 + 10;

int tr[N][26], cnt[N], idx;

// ASCLL码 
// a -> 0, b -> 1
// (s[i] - 'a')


void insert(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i ++){
		int t = s[i] - 'a';
		if(!tr[p][t]) tr[p][t] = ++ idx;
		p = tr[p][t];
	}
	cnt[p] ++;
}

int query(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i ++){
		int t = s[i] - 'a';
		if(!tr[p][t]) return 0;
		p = tr[p][t];
	}
	return cnt[p];
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i ++){
		string op, s; cin >> op >> s;
		if(op == "I") insert(s);
		else cout << query(s) << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    //solve();
    for(char x = 'a'; x <= 'z'; x ++){
    	cout << x << ' ' << (int)x << endl;
    }
    return 0;
}