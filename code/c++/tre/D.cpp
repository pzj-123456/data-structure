#include <iostream>
#include<vector>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

const int N = 1e4;
int tr[N * 20][26], cnt[N * 20], idx = 0;

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

void check(string s){
	string pre;
	int p = 0; bool flag = 1;
	for(int i = 0; i < (int)s.length(); i ++){
		int t = s[i] - 'a';
		p = tr[p][t];
		if(cnt[p] == 1){
			pre = s.substr(0, i + 1); flag = 0;
			break;
		}
	}
	if(flag) pre = s;
	cout << s << " " << pre << endl;
}

void solve(){
	vector<string> st;
	string s;
	while(cin >> s) {
		if(s == "#") break;
		insert(s);
		st.push_back(s);
	}
	for(int i = 0; i < (int)st.size(); i ++){
		check(st[i]);
	}
}

int main(){
    solve();
    return 0;
}