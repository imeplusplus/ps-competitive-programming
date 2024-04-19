#include <bits/stdc++.h>

using namespace std;

// you've got to notice that the best answer will the the height of the largest tree

// time complexity: O(n)

const int N = 2e3 + 7;

vector<int> adj[N];

int dfs(int x) {
    int cur = 0;
    for(auto e : adj[x]) {
        cur = max(cur, dfs(e));
    }
    return cur + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> check;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x != -1) {
            adj[x].push_back(i);
        } else {
            check.push_back(i);
        }
    }
    int ans = 0;
    for(auto e : check) {
        ans = max(ans, dfs(e));
    }
    cout << ans << "\n";
    return 0;
}
