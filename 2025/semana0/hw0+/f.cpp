#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ac = 0, wa = 0, tle = 0, re = 0;
    while(n--) {
        string s;
        cin >> s;
        if(s == "AC") {
            ac++;
        } else if(s == "WA") {
            wa++;
        } else if(s == "TLE") {
            tle++;
        } else {
            re++;
        }
    }
    cout << "AC x " << ac << "\n";
    cout << "WA x " << wa << "\n";
    cout << "TLE x " << tle << "\n";
    cout << "RE x " << re << "\n";
    return 0;
}