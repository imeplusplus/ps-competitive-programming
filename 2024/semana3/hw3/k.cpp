#include <bits/stdc++.h>
 
using namespace std;

// simply keep on greedily taking tha largest first, which is done with a priority queue
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    while(n--) {
        char c;
        int x;
        cin >> c >> x;
        pq.push({x, c});
    }
    int c = 0, f = 0, p = 0, q = 0, cnt = 0;
    while(!pq.empty()) {
        auto x = pq.top(); pq.pop();
        if(x.second == 'C') {
            if(c + x.first <= t) {
                c += x.first;
                cnt++;
            }
        } else if(x.second == 'F') {
            if(f + x.first <= t) {
                f += x.first;
                cnt++;
            }
        } else if(x.second == 'P') {
            if(p + x.first <= t) {
                p += x.first;
                cnt++;
            }
        } else {
            if(q + x.first <= t) {
                q += x.first;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
