#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '1') {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    return 0;
}