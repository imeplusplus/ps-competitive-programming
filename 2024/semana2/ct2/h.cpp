#include <bits/stdc++.h>

using namespace std;

int binexp(long long a, long long n) {
    long long res = 1;
    a %= 10;
    while(n) {
        if(n & 1) {
            res = (res * a) % 10;
        }
        a = (a * a) % 10;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << binexp(1378, n) << "\n";
    return 0;
}
