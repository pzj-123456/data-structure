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
    while(cin >> n >> m){
        if(m >= n){
            for(int i = n; i < m; i ++){
                cout << i << ' ';
            }
            cout << m;
        }
        else if(m < n){
            if(n % (m + 1)) cout << n % (m + 1);
            else cout << "none";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}