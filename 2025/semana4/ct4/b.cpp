#include <bits/stdc++.h>

using namespace std;

bool f1(long long val, long long k, long long x) {
    return k - val >= x;
}
bool f2(long long val, long long k, long long y) {
    return k - val <= y;
}

int main() {
    long long t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        vector<long long> v(n);
        long long s = 0;
        for (long long i = 0; i < n; i++) cin >> v[i], s += v[i];
        sort(v.begin(), v.end());
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            long long l = i, r = i;
            long long k = s - v[i];
            for (long long b = (n - i) / 2 + 1; b; b >>= 1) {
                while (l + b < n && f1(v[l + b], k, x)) l += b;
            }
            for (long long b = (n - i) / 2 + 1; b; b >>= 1) {
                while (r + b < n && !f2(v[r + b], k, y)) r += b;
            }
            ans += max(0ll, l - r);
        }
        cout << ans << "\n";
    }
    return 0;
}