#include <bits/stdc++.h>

using namespace std;

// let's make a recursive function that calculates what the question asks at each step

// time complexity: O(n^2)

const int N = 107;
int v[N], ans[N];

void calc(int l, int r, int dep = 0) {
    if(l > r) {
        return;
    }
    int ind = -1, mx = 0;
    for(int i = l; i <= r; i++) {
        if(v[i] > mx) {
            mx = v[i];
            ind = i;
        }
    }
    ans[ind] = dep;
    calc(l, ind - 1, dep + 1);
    calc(ind + 1, r, dep + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        calc(0, n - 1);
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}