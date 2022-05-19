#include <bits/stdc++.h>
 
using namespace std;

/*

Veja que o melhor caso para y é quando y = m ^ n. Depois, só voltar fazendo recursão para ver que x tem que ser: x = ((m ^ n) - 1) / (m - 1).
Tem que usar o fexp

Complexidade do Código: O(log(mod))

*/
 
const int mod = 1e9 + 7;
 
long long binexp(long long a, long long n) {
    long long res = 1;
    while(n) {
        if(n & 1) {
            res = (res * a) % mod;
        }
         a = (a * a) % mod;
         n >>= 1;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long m, n;
        cin >> m >> n;
        long long y = binexp(m, n);
        long long x = ((y - 1) * binexp(m - 1, mod - 2)) % mod;
        cout << x << " " << y << "\n";
    }
    return 0;
}
