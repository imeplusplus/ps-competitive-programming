#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    unordered_map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < 31; j++) {
            if (x & (1 << j)) m[j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        x = 0;
        for (int j = 0; j < 31; j++) {
            if (m[j]) {
                m[j]--;
                x |= (1 << j);
            }
        }
        cout << x << " ";
    }
}