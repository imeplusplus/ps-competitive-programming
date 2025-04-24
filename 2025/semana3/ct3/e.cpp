#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    int ind = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            ans += n - i - 1;
            ind = i;
            break;
        }
    }
    for (int i = 0; i < ind; i++) {
        ans += s[i] != '0';
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}