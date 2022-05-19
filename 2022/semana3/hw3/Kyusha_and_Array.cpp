#include <bits/stdc++.h>

using namespace std;

/*

Veja que para que a condição do problema ocorra, o menor número do vetor tem que dividir todos os números.

Complexidade do Código: O(n)

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
    }
    bool pode = true;
    for(int i = 0; i < n; i++) {
        if(v[i] % mn != 0) {
            pode = false;
            break;
        }
    }
    cout << (pode ? mn : -1) << "\n";
    return 0;
}
