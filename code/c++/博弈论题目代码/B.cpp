#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

// (a + b) % 6 = 3
// 2 -> 1, 5 -> 4，6 -> 3

void solve(){
	int n; cin >> n;
	int res = 0;
	for(int i = 1; i <= n; i ++){
		int x; cin >> x;
		if(i % 6 == 0 || i % 6 == 2 || i % 6 == 5)
			res ^= x;
	}
	cout << (res ? "Alice" : "Bob") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int T; cin >> T;
    for(int i = 1; i <= T; i ++){
    	cout << "Case " << i << ": ";
    	solve();
    }
    return 0;
}