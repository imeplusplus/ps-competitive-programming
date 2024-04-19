// o jeito de continuamente encontrar a subsequência é imaginar que o array b é infinito e cíclico, então a ideia é guardar as posições em que cada valor está,
// e enquanto anda por b, achar a posição mais próxima que existe. Para fazer isso rápido, fazemos uma busca binária no vetor onde guardamos as posições.
// Caso não ache, quer dizer que precisamos dar um ciclo em b.

// Complexidade: O(nlogn)

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(auto &e : a) cin >> e;
        for(auto &e : b) cin >> e;
        map<int, vector<int>> mp;
        for(int i = 0; i < m; i++) {
            mp[b[i]].push_back(i);
        }
        int prev = -1, ans = 1;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(mp.find(a[i]) == mp.end()) {
                ok = false;
                break;
            }
            int ind = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), prev) - mp[a[i]].begin();
            if(ind == mp[a[i]].size()) {
                ans++;
                prev = mp[a[i]].front();
            } else {
                prev = mp[a[i]][ind];
            }
        }
        cout << (ok ? ans : -1) << "\n";
    }
    return 0;
}
