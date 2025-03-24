#include <bits/stdc++.h>

using namespace std;

int check(string &s, int p) {
    int t = 0;
    for (int i = max(0, p - 3); i <= min(p, (int)s.size() - 4); i++) {
        if (s[i] == '1' &&
            s[i + 1] == '1' &&
            s[i + 2] == '0' &&
            s[i + 3] == '0') {
            t++;
        }
    }
    return t;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t, n, k, b, c;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cin >> n;
        int t = 0;
        for (int i = 0; i <= (int)s.size() - 4; i++) {
            if (s[i] == '1' &&
                s[i + 1] == '1' &&
                s[i + 2] == '0' &&
                s[i + 3] == '0') {
                t++;
            }
        }
        char v;
        int p;
        while (n--) {
            cin >> p >> v;
            p--;
            int prev = check(s, p);
            s[p] = v;
            int aft = check(s, p);
            t += aft - prev;
            if (t)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}