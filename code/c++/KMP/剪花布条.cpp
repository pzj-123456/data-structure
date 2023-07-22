#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int Next[N];

void getNext(string s) {
    Next[1] = 0;
    int i = 1, j = 0;
    while(i < s.length()) {
        if(j == 0 || s[i] == s[j]) Next[++i] = ++j;
        else j = Next[j];
    }
}

int find_index(string s1, string s2, int pos) {
    int i = pos, j = 1;
    while(i < s1.length() && j < s2.length()) {
        if(j == 0 || s1[i] == s2[j]) i++, j++;
        else j = Next[j];
    }
    if(j == s2.length()) return i;
    return -1;
}

int main() {
    string s1, s2;
    while(cin >> s1, s1 != "#") {
        cin >> s2;
        s1 = ' ' + s1;s2 = ' ' + s2;
        getNext(s2);
        int pos = 1, cnt = 0;
        while(true) {
            pos = find_index(s1, s2, pos);
            if(pos == -1) break;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}