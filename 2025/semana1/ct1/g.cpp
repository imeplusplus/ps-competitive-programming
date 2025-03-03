#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0, x; i < n; i++) {
        cin >> v[i];
    }
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        /*
        Vamos procura o primeiro elemento maior que v[i] no array.
        Se ele existir, substitui pelo atual pq eh menor.
        Se ninguem for maior que o atual ele sera uma nova base.

        Aqui eh otimo colocar o elemento em cima do primeiro que eh maior
        pq ha uma maior chance de caber um elemnto em cima deopis
        */
        auto it = s.upper_bound(v[i]);
        if (it != s.end()) s.erase(it);
        s.insert(v[i]);
    }
    cout << s.size() << "\n";
    return 0;
}