#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;

void solve(){
    int m;
    while(cin >> m && m){
        vector<int> arr(m);
        int k = 0;
        for(int& x : arr) cin >> x, k ^= x;
        if(k){
            cout << "Yes\n";
            for(int i = 0; i < m; i ++){
                if((arr[i] ^ k) < arr[i]){
    cout << arr[i] <<' '<< (arr[i] ^ k) << "\n";
                }
            }
        }
        else cout << "No\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    solve();
    return 0;
}