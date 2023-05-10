// complexidade do codigo: O(r logr)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        int n, r;
        cin >> n >> r;
        set<pair<int, int>> s;
        bool ok = true;
        for(int i = 0; i < r; i++) {
            int a, b;
            cin >> a >> b;
            if(s.find({a, b}) == s.end()) {
                // se não ta, eu adiciono
                s.insert({a, b});
            } else {
                // se apareceu antes (ou seja, aparece >=2 vezes), é impossivel
                ok = false;
            }
        }
        cout << "Scenario #" << tt << ": ";
        cout << (ok ? "possible" : "impossible") << endl;
    }
    return 0;
}