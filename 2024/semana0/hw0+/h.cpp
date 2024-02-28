#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        // pelos limites do problema, o numero na permutacao nao irá exceder 200
        vector<int> cnt(200);
        bool pode = true;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            cnt[v[i]]++;
            // se o numero aparecer mais de 1 vez não é uma permutação
            if(cnt[v[i]] > 1) {
                pode = false;
            }
        }
        int sum = 0, sz = n;
        for(int i = 1; i <= sz; i++) {
            if(cnt[i] == 0) {
                // se não existe, tenho que adicionar
                sum += i;
                sz++;
            }
        }
        while(sum < s) {
            // agora vou ficar preenchendo no final até completar a soma
            sz++;
            sum += sz;
        }
        if(sum != s) {
            // se nao for igual, nao tem como fazer virar uma permutacao
            pode = false;
        }
        if(pode) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}