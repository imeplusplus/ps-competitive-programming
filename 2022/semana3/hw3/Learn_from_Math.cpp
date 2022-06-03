#include <bits/stdc++.h>
 
using namespace std;

/*

Use o crivo para encontrar os primos, aí depois pode ficar conferindo direto com todos os valores até n;

Complexidade do código: O(n * log(log(n))

*/
 
const int N = 1e6 + 7;
 
bool comp[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(long long i = 2; i < N; i++) {
        if(comp[i]) {
            continue;
        }
        for(long long j = i * i; j < N; j += i) {
            comp[j] = true;
        }
    }
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        if(comp[i] and comp[n - i]) {
            cout << i << " " << n - i << "\n";
            return 0;
        }
    }
    return 0;
}
