#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) cin >> v[i], m[v[i]]++;
        int ans = 0, l = -1, r = 0, mxl = -1, mxr = -1;
        for (int i = 0; i < n; i++) {
            if (m[v[i]] == 1)
                r++;
            else {
                if (r - l > 1) {
                    if (r - l - 1 > ans) ans = r - l - 1, mxl = l + 1, mxr = r - 1;
                }
                l = i;
                r = i + 1;
            }
        }
        if (r - l > 1) {
            if (r - l - 1 > ans) ans = r - l - 1, mxl = l + 1, mxr = r - 1;
        }
        if (ans)
            cout << mxl + 1 << " " << mxr + 1 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}