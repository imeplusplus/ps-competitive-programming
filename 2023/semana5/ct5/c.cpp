#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> lines(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> lines[i];
        }
        sort(lines.begin(), lines.end());
        vector<vector<int>> parabs;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            parabs.push_back({a, b, c});
        }
        for(int i = 0; i < m; i++) {
            if(parabs[i][2] <= 0) {
                cout << "NO" << endl;
                continue;
            }
            long long a = parabs[i][0], b = parabs[i][1], c = parabs[i][2];
            int d = ceil(sqrt(4 * a * c - 0.5));
            auto itr = lower_bound(lines.begin(), lines.end(), b - d + 1);
            if(itr == lines.end()) {
                cout << "NO" << endl;
                continue;
            }
            if(*itr >= b + d) {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            cout << *itr << endl;
        }
    }
    
    return 0;
}