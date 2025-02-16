#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // ordenar o vetor já que a resposta minima ocorrerá quando os elementos estiverem ordenados
    sort(v.begin(), v.end());
    // inicializar a resposta com valor grande
    int ans = 1000;
    for(int i = m - 1; i < n; i++) {
        // encontrando a diferenca
        ans = min(ans, v[i] - v[i - m + 1]);
    }
    cout << ans << "\n";
    return 0;
}