#include <bits/stdc++.h>

using namespace std;

/*

Veja que divide-se em dois casos, caso n par e n ímpar:
n par: n ^ 2 + x ^ 2 = (x + 1) ^ 2
n ímpar: n ^ 2 + (x - 1) ^ 2 = (x + 1) ^ 2

Complexidade do Código: O(1)

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    if(n < 3) {
        cout << "-1\n";
        return 0;
    }
    if(n % 2 == 1) {
        cout << (n * n - 1) / 2 << " " << (n * n - 1) / 2 + 1 << "\n";
    } else {
        cout << (n * n / 4) - 1 << " " << (n * n / 4) + 1 << "\n";
    }
    return 0;
}
