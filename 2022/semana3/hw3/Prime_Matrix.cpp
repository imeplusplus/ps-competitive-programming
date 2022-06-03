#include <bits/stdc++.h>

using namespace std;

/*

Primeiro, é necessário encontrar os primos rapidamente (assim, utiliza-se o crivo). Após isso, passar por todas as colunas e depois por todos as linhas,
ao olhar os números, primeiro confere se é primo; caso não seja, você fica incrementando até encontrar o primo mais perto que é maior.
Pode-se fazer isso pois, na escala em que trabalhamos, os primos são relativamente próximos entre si.

Complexidade do Código: O(n^2)

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
    comp[1] = true; // para efeitos de comparação, marca-se o número 1 como composto para não ser confundido como primo.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    long long ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        long long tmp = 0;
        for(int j = 0; j < m; j++) {
            if(!comp[v[i][j]]) {
                continue;
            } 
            int x = v[i][j];
            while(comp[x]) {
                x++;
            }
            tmp += x - v[i][j];
        }
        ans = min(ans, tmp);
    }
    for(int j = 0; j < m; j++) {
        long long tmp = 0;
        for(int i = 0; i < n; i++) {
            if(!comp[v[i][j]]) {
                continue;
            }
            int x = v[i][j];
            while(comp[x]) {
                x++;
            }
            tmp += x - v[i][j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
