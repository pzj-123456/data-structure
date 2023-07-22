#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

void solve(){
	int n, m;
	while(cin >> n >> m && n && m){
		if(n % 2 == 0 || m % 2 == 0)
		   cout << "Wonderful!\n";
		else
		   cout << "What a pity!\n";
	} 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}