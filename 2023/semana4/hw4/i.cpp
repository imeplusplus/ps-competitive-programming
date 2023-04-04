#include <bits/stdc++.h>

using namespace std;

// do a DSU and then unite the leader of each disjoint set

const int N = 1e5 + 7;

int par[N], sz[N];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool unite(int a, int b) {
    if((a = find(a)) == (b = find(b))) {
        return false;
    }
    if(sz[a] > sz[b]) {
        swap(a, b);
    }
    par[a] = b;
    sz[b] += sz[a];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    int n;
    cin >> n;
    vector<pair<int, int>> rem;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(!unite(a, b)) {
            rem.push_back({a, b});
        }
    }
    vector<int> ot;
    for(int i = 1; i <= n; i++) {
        if(par[i] == i) {
            ot.push_back(i);
        }
    }
    int a = ot.back(); ot.pop_back();
    vector<vector<int>> ans;
    while(ot.size()) {
        ans.push_back({rem.back().first, rem.back().second, a, ot.back()});
        rem.pop_back();
        ot.pop_back();
    }
    cout << ans.size() << "\n";
    for(auto e : ans) {
        for(auto x : e) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}