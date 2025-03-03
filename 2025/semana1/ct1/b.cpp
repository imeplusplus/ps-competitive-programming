#include <bits/stdc++.h>

using namespace std;
const int N = 44721;
int v[N];
/*
v = [0, 1, 3, 6, 10, 15, 21, ...]
Shiftar elementos de l.
O indice do primeiro valor maior que r sera o tamanho maximo do array
v = [l, l+1, l+3, l+6, ...]
*/
int main() {
    int t, l, r;
    int cnt = 0, i = 0;
    while (cnt < 1e9) {
        v[i++] = cnt;
        cnt += i;
    }
    cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << upper_bound(v, v + N, r - l) - v << "\n";
    }
    return 0;
}