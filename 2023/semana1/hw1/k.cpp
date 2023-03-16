#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        string s;
        cin >> s;
        cout << s.size() << "\n";
    } else {
        string a, b;
        cin >> a >> b;
        if(a.find(b) != string::npos) {
            cout << a.size() << "\n";
            return 0;
        } else if(b.find(a) != string::npos) {
            cout << b.size() << "\n";
            return 0;
        }
        int ans = a.size() + b.size();
        for(int i = 1; i <= min(a.size(), b.size()); i++) {
            if(a.substr(0, i) == b.substr((int)b.size() - i, i)) {
                ans = min(ans, (int)a.size() + (int)b.size() - i);
            }
            if(b.substr(0, i) == a.substr((int)a.size() - i)) {
                ans = min(ans, (int)a.size() + (int)b.size() - i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}