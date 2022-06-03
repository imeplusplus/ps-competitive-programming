#include <bits/stdc++.h>

using namespace std;

/*

A maneira de pegar a maior quantidade de divisores é pegando a fatoração prima do número.
Dessa forma, caso a quantidade seja maior que o k, você pode ir mulitplicando até a quantidade de números presentes der k.

Complexidade do Código: O(sqrt(n))

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> f;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }
    if(n > 1) {
        f.push_back(n);
    }
    if(f.size() < k) {
        cout << -1 << "\n";
    } else {
        while(f.size() > k) {
            // dentro desse while, eu guardo o último número do vetor em uma variável separada,
            // removo o último número, e multiplico o novo último pelo valor guardado
            int x = f.back();
            f.pop_back();
            f.back() *= x;
        }
        for(auto e : f) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
