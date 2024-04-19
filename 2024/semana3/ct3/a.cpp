#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;
    long long n, t;
    cin >> n >> t;
    long double base = 1.000000011, ans = n;
    while(t) {
        if(t & 1) {
            ans *= base;
        }
        base *= base;
        t >>= 1;
    }   
    cout << ans << "\n";
    return 0;
}
