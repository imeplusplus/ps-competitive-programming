#include <bits/stdc++.h>
 
using namespace std;

/*

Primeiro, vamos ordernar o vetor ao contrário, fazendo ser decrescente. Então, necessariamente, os primeiros k números do vetor farão parte da soma que queremos.
Agora, vamos pegar o menor número que pertence a esse conjunto, vamos contar quantas vezes ela existe nos primeiros k, e quantas vezes ela existe no vetor todo.
Dessa forma, basta fazer a combinação de pegar todas que existem e colocar em suas posições dentro dos primeiros k.

Complexidade do Código: O(n)

*/
 
const int mod = 1e9 + 7;
 
vector<long long> fact = {1, 1};
 
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
 
long long ncr(int n, int r) {
    long long ans = fact[n];
    ans = (ans * binexp(fact[r], mod - 2)) % mod;
    ans = (ans * binexp(fact[n - r], mod - 2)) % mod;
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < 2000; i++) {
        fact.push_back((fact[i - 1] * i) % mod);
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        int c = 0, r = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == v[k - 1]) {
                c++;
            }
        }
        for(int i = 0; i < k; i++) {
            if(v[i] == v[k - 1]) {
                r++;
            }
        }
        cout << ncr(c, r) << "\n";
    }
    return 0;
}
