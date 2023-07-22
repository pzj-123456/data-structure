#include <iostream>

using namespace std;

int main() {
    int n, i, len;
    string s, sub;
    cin >> n >> s;
    sub = s[0], i = len = 1;

    while(i < s.length()) {
        int tp = len;
        bool flag;
        while((i + 1) % tp != 0) tp++;
        if(tp == i + 1) continue;
        
        // for(int j = 0;)
    }


    return 0;
}