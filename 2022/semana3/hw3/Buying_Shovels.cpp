#include <bits/stdc++.h>

using namespace std;
/*

A ideia da questão é o seguinte: achar o menor número, múltiplo de n, tal que sua divisão por n seja menor ou igual a k.

Complexidade do Código: O(sqrt(n))

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n, k;
        cin >> n >> k;
        long long ans = n;
        for(long long i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i <= k) {
                    ans = min(ans, n / i);
                }
                if(n / i <= k) {
                    ans = min(ans, i);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
