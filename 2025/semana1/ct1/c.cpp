#include <bits/stdc++.h>

using namespace std;
vector<long long> v;
long long n, t;

bool f(long long x) {
    // checa o score para um tempo arbritario x e compara com o target
    long long sm = 0;
    for (int i = 0; i < n; i++) {
        sm += x / v[i];
        if (sm >= t) return true;
    }
    return false;
}

int main() {
    cin >> n >> t;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // binary search pra achar o primeiro tempo em que o score eh >= t
    long long ans = 0;
    for (long long b = 1e18 / 2; b; b >>= 1) {
        while (ans + b <= 1e18 && !f(ans + b)) {
            ans += b;
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}