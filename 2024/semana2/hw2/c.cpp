#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<pair<int, int>> s;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        s.insert(v[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // verificar se é divisível por 2
            if((v[i].first + v[j].first) % 2 != 0 or (v[i].second + v[j].second) % 2 != 0) {
                continue;
            }
            pair<int, int> ref = {(v[i].first + v[j].first) / 2, (v[i].second + v[j].second) / 2};
            if(s.find(ref) != s.end()) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
