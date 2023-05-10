// complexidade do codigo: O(n logn).

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
        vector<int> a(n), b(n);
        map<pair<int, int>, vector<int>> changes;
        // changes[{time, 0}] = [who entered at time]
        // changes[{time, 1}] = [who left at time]
        // we must process entering first
        vector<int> ans(n);
        set<int> rooms;
        for(int i = 0; i < n; i++) {
            rooms.insert(i);
            cin >> a[i] >> b[i];
            changes[{a[i], 0}].push_back(i);
            changes[{b[i], 1}].push_back(i);
        }

        int cntRooms = 0, maxRooms = 0;

        // passing in increasing order of time (and entering first)
        for(auto e : changes) {
            if(e.first.second == 0) {
                for(auto i : e.second) {
                    ans[i] = *rooms.begin();
                    rooms.erase(rooms.begin());
                    cntRooms++;
                }
                maxRooms = max(maxRooms, cntRooms);
            } else {
                for(auto i : e.second) {
                    rooms.insert(ans[i]);
                    cntRooms--;
                }
            }
        }
        cout << maxRooms << endl;
        for(int i = 0; i < n; i++)
            cout << ans[i] + 1 << " ";
    }
    return 0;
}