// complexidade do codigo: O(n)

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
        int n;
        cin >> n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        deque<int> q;
        q.push_back(p[0]);
        for(int i = 1; i < n; i++) {
            if(p[i] < q.front())
                q.push_front(p[i]);
            else
                q.push_back(p[i]);
        }
        // printar na ordem (ou pode fazer um for tbm)
        // for(int i = 0; i < n; i++)
        //     cout << q[i] << " ";
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}