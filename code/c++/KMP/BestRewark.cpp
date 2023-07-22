#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int q_sum[N], sum;
int mp[26];
int P[N];

int main() {
    int T; cin >> T;
    while(T--) {
        string str, s;
        for(int i = 0; i < 26; i++) cin >> mp[i];
        cin >> str;
        s = "^#";
        for(int i = 0; i < str.length(); i++) {
            s += str[i];
            s += '#';
        }
        s += '$';
        int R = 0, index = 0;
        for(int i = 1; i < s.length()-1; i++){
            int j = 2 * index - i;
            P[i] = i < R ? min(P[j], R - i) : 1;
            while(s[i - P[i]] == s[i + P[i]]) P[i] ++;
            if(R < i + P[i]) {
                R = i + P[i];
                index = i;
            }
        }
        
        sum = q_sum[0] = 0;
        for(int i = 1; i < s.length() - 1; i++) {
            if(s[i] == '#') q_sum[i] = q_sum[i-1];
            else {
                q_sum[i] = mp[s[i] - 'a'] + q_sum[i-1];
                sum += mp[s[i] - 'a'];
            }
        }
        // cout << sum << endl;
        int res = 0;
        for(int i = 3; i < s.length()-2; i += 2) {
            int tp = 0, lmid = i/2 + 1, rmid = (s.length() + i - 1)/2;
            if(P[lmid] + lmid - 1 == i) tp += q_sum[i];
            if(rmid - P[rmid] + 1 == i) tp += sum - q_sum[i];
            res = max(res, tp);
        }
        cout << res << endl;
    }

    return 0;
}