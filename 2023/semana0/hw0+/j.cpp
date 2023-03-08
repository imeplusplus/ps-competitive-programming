#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, s, r;
        cin >> n >> s >> r;
        // valor maximo que roubou
        int mx = s - r;
        vector<int> v(n, mx);
        int cur = mx * n;
        // setei todos os valores do vetor para o maximo, entao vou subtrair até chegar a soma em r
        for(int i = 0; i < n; i++) {
            if(cur - s >= mx) {
                v[i] = 1;
                cur -= mx - 1;
            } else {
                v[i] -= cur - s;
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}