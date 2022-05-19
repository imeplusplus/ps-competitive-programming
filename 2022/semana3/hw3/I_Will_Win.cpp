#include <bits/stdc++.h>
 
using namespace std;

/*

Veja que a probabilidade de ganhar n jogos será (p / q) ^ n

Complexidade do Código: log(mod)

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
        long long n, p, q;
        cin >> n >> p >> q;
        p %= mod;
        q %= mod;
        long long prob = (p * binexp(q, mod - 2)) % mod;
        cout << (binexp(prob, n)) % mod << "\n";
    }
    return 0;
}
