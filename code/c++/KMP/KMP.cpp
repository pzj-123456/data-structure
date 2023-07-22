#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int Next[N];

void getNext(string s) {
    Next[0] = -1;
    int i = 0, j = -1;
    while(i < s.length()) {
        if(j == -1 || s[i] == s[j]) Next[++i] = ++j;
        else j = Next[j];
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    getNext(s2);
    int dis = 0;
    // cout << getPos(s1, s2, 1) + 1 << endl;
    
    for(int i = 0, j = 0; i < s1.length(); i++) {
        while(j != -1 && s1[i] != s2[j]) j = Next[j];
        if(j == -1 || s1[i] == s2[j]) j++;
        if(j == s2.length())
            cout << i - j + 1 << ' ';
    }

    // for(int i = 1; i <= s2.length(); i++)
    //     cout << Next[i] << ' ';
    // cout << endl;

    return 0;
}