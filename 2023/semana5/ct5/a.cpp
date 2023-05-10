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
    map<string, pair<int, string>> maxDrag, minDrag;
    while(t--) {
        string command;
        cin >> command;
        if(command == "ask") {
            string habitat;
            cin >> habitat;
            cout << minDrag[habitat].second << " " << maxDrag[habitat].second << endl;
        } else {
            string habitat, name;
            int size;
            cin >> habitat >> name >> size;
            if(minDrag.count(habitat) == 0) {
                minDrag[habitat] = {size, name};
                maxDrag[habitat] = {size, name};
            } else {
                if(size < minDrag[habitat].first)
                    minDrag[habitat] = {size, name};
                if(size > maxDrag[habitat].first)
                    maxDrag[habitat] = {size, name};
            }
        }
    }
    return 0;
}