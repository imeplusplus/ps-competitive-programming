#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
typedef long long ll;
int n;
int g[N][N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> g[i][j];
    }
    deque<int> ans;
    vector<int> vis(2 * n + 1);
    for (int i = 0; i < n; i++) ans.push_back(g[i][0]), vis[g[i][0]] = 1;
    for (int j = 1; j < n; j++) ans.push_back(g[n - 1][j]), vis[g[n - 1][j]] = 1;
    for (int i = 1; i <= 2 * n; i++)
        if (!vis[i]) ans.push_front(i);
    for (auto& e : ans) cout << e << " ";
    cout << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}