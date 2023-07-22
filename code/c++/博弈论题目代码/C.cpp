#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

void solve(){
	int t; cin >> t; 
    for(int i = 1; i <= t; i ++){
   	    int n, k; cin >> n >> k;
   	    cout<<"Case "<< i <<": ";
   	    if(n <= k || (k == 1 && n % 2)) cout << "first\n";
   	    else cout << "second\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}