#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // ordenar somente os primeiros k elementos
    sort(v.begin(), v.begin() + k);
    for(int i = 0; i < k; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}