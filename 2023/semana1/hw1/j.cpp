#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        if(a[0] == b[0]) {
            cout << "YES\n";
            cout << a[0] << "*\n";
            continue;
        }
        if(a.back() == b.back()) {
            cout << "YES\n";
            cout << "*" << a.back() << "\n";
            continue;
        }
        bool foi = false;
        int ind = 0;
        for(int i = 0; i + 1 < (int)a.size(); i++) {
            for(int j = 0; j + 1 < (int)b.size(); j++) {
                if(a[i] == b[j] and a[i + 1] == b[j + 1]) {
                    ind = i;
                    foi = true;
                    break;
                }
            }
        } 
        if(foi) {
            cout << "YES\n";
            cout << "*" << a.substr(ind, 2) << "*\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}