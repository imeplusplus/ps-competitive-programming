#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l = 1, r = 1000, x;
    // binary search nas guesses ate achar o valor
    // maximo de log_2(1000) = 10 queries
    while (l < r) {
        int m = (l + r) / 2;
        cout << "? " << l << " " << m << "\n";
        cout.flush();  // colocar flush depois de todo print em questao interativa
        cin >> x;
        if (x == l * m)  // produto continuou igual, entao esta a esquerda de x
            l = m + 1;
        else
            r = m;  // produto deu l*(m+1), esta a direita de x
    }
    cout << "! " << l << "\n";
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}