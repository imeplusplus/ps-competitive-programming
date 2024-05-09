// complexidade: O(n)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    long long a[n], ans = 1e17;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    // como n é multiplo de k, o numero minimo de limpadores necessarios é n/k
    // e os possíveis conjuntos de limpadores são:
    // [0, k, 2k, ... ,], [1, 1 + k, 1 + 2k, ...], [2, 2 + k, 2 + 2k, ...,], ...
    // basta testar todos os conjuntos e ver qual tem o menor custo
    // cada um tem n/k elementos, e tem k conjuntos, então vamos apenas O(n / k * k) = O(n) operações 
    for(int i = 0; i < k; i++) {
        long long cost = 0;
        for(int j = 0; j < n; j += k)
            cost += a[i + j];
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
