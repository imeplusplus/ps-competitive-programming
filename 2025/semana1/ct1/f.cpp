#include <bits/stdc++.h>

using namespace std;
/*
Vamos parear todos os numeros cuja soma dao k no array.
Se a aparece x vezes e (k-a) aparece y vezes no array vamos formar
min(x,y) pares. Toda vez que alice escolhe um elemnto que tem par
incrementamos o score.
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> m;  // conta quantas vezes cada elemento aparece
        for (int i = 0, x; i < n; i++) cin >> x, m[x]++;
        int ans = 0;
        for (auto [key, v] : m) {
            if (m.count(k - key)) ans += min(v, m[k - key]);
        }
        ans >>= 1;  // tira os duplicados
        cout << ans << "\n";
    }
}