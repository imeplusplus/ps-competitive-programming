#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    // boxes[i] -> map com os numeros dos cartões que estão na caixa i e suas frequencias
    // cards[i] -> map com as caixas que o cartão i está
    map<int, map<int, int>> boxes, cards;
    for(int _ = 0; _ < q; _++) {
        int x, i, j;
        cin >> x;
        if(x == 1) {
            cin >> i >> j;
            // adiciono o cartão i na caixa j
            boxes[j][i]++;
            // adiciono a caixa j no cartão i
            cards[i][j]++;
        } else if(x == 2) {
            cin >> i;
            // pra cada cartão na caixa i
            for(auto e : boxes[i]) {
                // tenho que printar o número do cartão o número de vezes que ele está na caixa
                for(int j = 0; j < e.second; j++)
                    cout << e.first << " ";
            }
            cout << endl;
        } else if(x == 3) {
            cin >> i;
            // pra cada caixa que o cartão i está
            for(auto e : cards[i]) {
                // aqui basta printar o numero da caixa, não pede a quantidade
                cout << e.first << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
