#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int l[n];
    // mp[x] = quantidade de sapatos com tamanho x
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        mp[l[i]]++;
    }
    for(int _ = 0; _ < q; _++) {
        int x;
        cin >> x;
        auto itr = mp.lower_bound(x);
        if(itr == mp.end()) {
            cout << -1 << endl;
        } else {
            cout << itr->first << endl;
            // decremento a quantidade de sapatos com o tamanho que vendi pra ele
            mp[itr->first]--;
            // se não tem mais nenhum sapato com esse tamanho, eu removo do map
            if(mp[itr->first] == 0)
                mp.erase(itr->first);
        }
    }
    return 0;
}