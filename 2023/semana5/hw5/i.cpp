// complexidade do codigo: O(n^2 logn).
// Usando um unordered_map da pra reduzir pra O(n^2)  

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
        int n, x;
        cin >> n >> x;
        vector<long long> a(n);
        map<long long, int> mp;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        mp[a[0]] = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(mp.count(x - a[i] - a[j])) {
                    cout << mp[x - a[i] - a[j]] + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
            mp[a[i]] = i;
        }
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}