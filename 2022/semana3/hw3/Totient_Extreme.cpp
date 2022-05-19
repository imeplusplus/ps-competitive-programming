#include <bits/stdc++.h>
 
using namespace std;

/*

Ao analisar como os for loop funcionam, é como se fosse um polinômio ao quadrado, assim a solução fica da forma:
(phi[1] + phi[2] + phi[3] ... + phi[n]) ^ 2

Complexidade do Código: O(N * log(N))

*/
 
const int N = 1e4 + 7;
 
vector<unsigned long long> phi(N);
 
void totient() {
    for(int i = 0; i < N; i++) {
        phi[i] = i;
    }
    for(int i = 2; i < N; i += 2) {
        phi[i] >>= 1;
    }
    for(unsigned long long j = 3; j < N; j += 2) {
        if(phi[j] == j) {
            phi[j]--;
            for(unsigned long long i = 2 * j; i < N; i += j) {
                phi[i] = phi[i] / j * (j - 1);
            }
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    totient();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unsigned long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += phi[i];
        }
        ans *= ans;
        cout << ans << "\n";
    }
    return 0;
}
