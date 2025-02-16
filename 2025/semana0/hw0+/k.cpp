#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // matematica, não usar float pois pode ter problema de precisao
    // olhando para os limites do problema, temos que usar long long
    int cnt = 0;
    long long n, x, y, r;
    cin >> n >> x >> y >> r;
    while(n--) {
        long long a, b;
        cin >> a >> b;
        long long dist2 = (x - a) * (x - a) + (y - b) * (y - b);
        if(dist2 <= r * r) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}