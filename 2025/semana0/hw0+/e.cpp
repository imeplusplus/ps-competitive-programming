#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // ordenar para pegar os m menores elementos
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans += v[i];
    }
    cout << ans << "\n";
    return 0;
}