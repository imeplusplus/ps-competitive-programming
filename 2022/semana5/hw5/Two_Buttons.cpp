#include <bits/stdc++.h>

using namespace std;

/*

Você pode gulosamente ir dividindo por 2 quando der, a fim de chegar no resultado.

Complexidade do código: O(log(n))

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n >= m) {
        cout << n - m << "\n"; //esse caso seria só ficar somando um
    } else {
        int add = 0;
        while(m > n) {
            //conferindo caso seja ímpar ou não
            if(m & 1) {
                m++;
            } else {
                m /= 2;
            }
            add++;
        }
        cout << add + n - m << "\n";
    }
    return 0;
}
