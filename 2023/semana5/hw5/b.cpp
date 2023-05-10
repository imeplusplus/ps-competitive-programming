// complexidade do codigo: O(n)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


// note que o primeiro elemento vai sempre ser o maior encontrado até então
// então depois de passar por ele, vai ficar só "girando" o resto do array.
// vamos simular pra m < n. Se m < n temos a resposta direto, e se m >= n,
// então a resposta vai ser o o maior elemento e dq[(m - n - 1) % (n - 1) + 1] depois de simular
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        deque<int> dq;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            dq.push_back(a[i]);
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            ans.push_back({a, b});
            if(a > b) {
                dq.push_front(a);
                dq.push_back(b);
            } else {
                dq.push_front(b);
                dq.push_back(a);
            }
        }
        while(q--) {
            long long m;
            cin >> m;
            if(m <= n) {
                cout << ans[m - 1].first << " " << ans[m - 1].second << endl;
            } else {
                cout << ans[n - 1].first << " " << dq[(m - n - 1) % (n - 1) + 1] << endl;
            }
        }
    }
    return 0;
}