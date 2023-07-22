#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1e5 + 10;
int tr[N * 10][26], cnt[N * 10 * 26], idx = 0;

void insert(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i ++){
		int t = s[i] - 'a';
		if(!tr[p][t]) tr[p][t] = ++ idx;
		p = tr[p][t];
		cnt[p] ++;
	}
	return;
}

int check(string s){
	int p = 0;
	for(int i = 0; i < (int)s.length(); i ++){
		int t = s[i] - 'a';
		if(!tr[p][t]) return 0;
		p = tr[p][t];
	}
	return cnt[p];
}

void solve(){
	string s;
	while(getline(cin, s)){
    	if(s.size() == 0) break;
    	insert(s);
	}
	while(getline(cin, s)){
		cout << check(s) << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}