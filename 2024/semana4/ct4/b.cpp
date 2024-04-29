// DSU, just join if the type is the same

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> par(n * m), sz(n * m, 1);
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n * m; i++) par[i] = i;
    int res = 0;
    function<int(int)> find = [&](int a) {
        return par[a] == a ? a : par[a] = find(par[a]);
    };
    auto unite = [&](int a, int b) -> bool {
        if((a = find(a)) == (b = find(b))) return false;
        if(v[a / m][a % m] != v[b / m][b % m]) return false;
        if(sz[b] > sz[a]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
        return true;
    };
    for(int i = 0; i < n * m; i++) {
        res++;
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cin >> v[x][y];
        for(int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if(xx >= 0 and xx < n and yy >= 0 and yy < m) {
                res -= unite(x * m + y, xx * m + yy);
            }
        }
        cout << res << "\n";
    }
    return 0; 
}
