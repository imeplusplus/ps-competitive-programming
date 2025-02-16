#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    bool foi = false;
    for(int i = 0; i <= x; i++) {
        if(i * 2 + (x - i) * 4 == y) {
            foi = true;
        }
    }
    if(foi) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
