#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int cnt = 0;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        // subtrai o tamanho da string enquanto nao passar de 0
        for (int i = 0; i < n; i++) {
            int sz = (int)v[i].size();
            if (m - sz >= 0)
                cnt++, m -= sz;
            else
                break;
        }
        cout << cnt << "\n";
    }
    return 0;
}