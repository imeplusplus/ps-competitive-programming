// você já sabe de cara quanto tem que estar em cada posição do array, então basta você iterar em ordem, e quando você tem um índice cujo valor é maior
// que o que precisa, você guarda o resto separado, pois se chegar em outro índice que está abaixo do necessário, você pode pegar dessa parte que guardou
// e somar naquele próprio índice. basta ver se alguma hora não dá para fazer a segunda operação.
// Complexidade: O(n)

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int s = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            s += v[i];
        }
        s /= n;
        bool pode = true;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > s) {
                cur += v[i] - s;
            } else if(v[i] < s) {
                if(cur < s - v[i]) {
                    pode = false;
                    break;
                } else {
                    cur -= s - v[i];
                }
            }
        }
        cout << (pode ? "YES\n" : "NO\n");
    }
    return 0;
}
