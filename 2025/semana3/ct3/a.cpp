#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
int sz[N], lk[N], ans[N], v[N];
 
int find(int x) {
    while (x != lk[x]) x = lk[x];
    return x;
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    lk[b] = a;
    ans[a] += ans[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            lk[i] = i;
            ans[i] = 0;
        }
        for (int i = 1; i <= n; i++) cin >> v[i];
        cin >> s;
        for (int i = 1; i <= s.size(); i++)
            if (s[i - 1] == '0') ans[i] = 1;
        for (int i = 1; i <= n; i++) {
            unite(i, v[i]);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[find(i)] << " ";
        }
        cout << "\n";
    }
    return 0;
}