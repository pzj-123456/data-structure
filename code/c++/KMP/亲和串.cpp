#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int Next[N];
string s1, s2;

void getNext(string s) {
    Next[0] = -1;
    int i = 0, j = -1;

    while(i < s.length()) {
        if(j == -1 || s[i] == s[j]) Next[++i] = ++j;
        else j = Next[j];
    }
}

int main() {
    while(cin >> s1 >> s2) {
        s1 = s1 + s1;
        getNext(s2);

        int i = 0, j = 0, flag = 0;
        while(i < s1.length()) {
            if(j == -1 || s1[i] == s2[j]) i++, j++;
            else j = Next[j];
            if(j == s2.length()) {
                flag = 1;
                cout << "yes" << endl;
                break;
            }
        }
        if(flag == 0) cout << "no" << endl;
    }

    return 0;
}