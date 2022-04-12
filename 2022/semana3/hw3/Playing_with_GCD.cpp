#include <bits/stdc++.h>
 
using namespace std;
 
/*

Vamos pensar em um sub problema: para um número n, queremos todos os números que não são coprimos com esses, ou seja, meio que o inverso da função phi.
Então, a resposta para esse sub problema é somente n - phi(n). Agora, para resolver para todos os casos, somente fazer a soma dos prefixos de cada um desses sub problemas.

Complexidade do Código: O(n * log(n))

*/

const int N = 1e5 + 7;
 
long long phi[N];
 
void totient() {
    for(int i = 1; i < N; i++) {
        phi[i] = i;
    }
    for(int i = 2; i < N; i += 2) {
        phi[i] >>= 1;
    }
    for(int j = 3; j < N; j += 2) {
        if(phi[j] == j) {
            phi[j]--;
            for(int i = 2 * j; i < N; i += j) {
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
    vector<int> ans(N);
    for(int i = 2; i < N; i++) {
        ans[i] += ans[i - 1];
        ans[i] += i - phi[i];
    }
    for(int ii = 1; ii <= t; ii++) {
        cout << "Case " << ii << ": ";
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
} 
