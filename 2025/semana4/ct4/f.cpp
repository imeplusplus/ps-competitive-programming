#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    double t, x;
    cin >> t >> n;
    t *= 4 * atan(1) / 180;
    set<pair<double, double>> s;
    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        double l = 1.0 * h / tan(t);
        s.insert({x, x + l});
    }
    double mx = s.begin()->first;
    double ans = 0;
    for (auto e : s) {
        if (e.first > mx) mx = e.first;
        ans += max(0.0, e.second - mx);
        mx = max(mx, e.second);
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}