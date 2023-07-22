#include <iostream>

using namespace std;

int a[26];
string s1, s2;

void solve() {
    cin >> s1 >> s2;
    for(int i = 0; i < 26; i++) a[i] = 0;
    for(int i = 0; i < s1.length(); i++) a[s1[i] - 'a'] ++;
    for(int i = 0; i < s2.length(); i++) a[s2[i] - 'a'] --;
    
    bool flag = true;
    int x = 0;
    while(s2[0] == s2[x]) x++;
    if(s2[0] > s2[x]) flag = true;
    else flag = false;

    for(int i = 0; i < 26; i++) {
        if(flag && i + 'a' == s2[0]) cout << s2;
        while(a[i]--) cout << char(i + 'a');
        if(!flag && i + 'a' == s2[0]) cout << s2;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}