#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> ans;
vector<int> tmp;
set<int> s;

bool prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

void bt(int cur = 1) {
    tmp.push_back(cur);
    s.erase(cur);
    for(int i = 1; i <= n; i++) {
        if(s.find(i) != s.end() and prime(cur + i)) {
            bt(i);
        }
    }
    if(tmp.size() == n and prime(cur + tmp.front())) {
        ans.push_back(tmp);
    }
    s.insert(cur);
    tmp.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(cin >> n) {
        if(t != 1) {
            cout << "\n";
        }
        ans.clear(); tmp.clear(); s.clear();
        for(int i = 1; i <= n; i++) {
            s.insert(i);
        }
        bt();
        cout << "Case " << t++ << ":\n";
        for(auto e : ans) {
            for(int i = 0; i < (int)e.size(); i++) {
                cout << e[i] << " \n"[i == (int)e.size() - 1];
            }
        }
    }
    return 0;
}
