// complexidade do codigo: O(n logn)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }
        int ans = 0;
        for(auto e : mp) {
            // e -> (x, mp[x])
            // se o elemento x ocorrer menos que x vezes, tem que tirar e.second - e.first
            // se não, precisa tirar e.second
            ans += (e.second >= e.first ? e.second - e.first : e.second);
        }
        cout << ans << endl;

    }
    return 0;
}
