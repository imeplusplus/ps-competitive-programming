// complexidade do código: O(n)

#include <bits/stdc++.h>

using namespace std;

//usar o valor do vetor dado como posição no vetor resposta e a posição como valor

const int N = 1e5 + 5;

int resposta[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int pos;
        cin >> pos;
        resposta[pos] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << resposta[i] << " ";
    }
    cout << "\n";
    return 0;
}
