// complexidade do código: O(nlog(n))

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // encontrar a posição ideal de inserir a nova altura
        auto k = upper_bound(v.begin(), v.end(), x);
        if(k == v.end()) {
            // se não houver lugar onde colocar, então é melhor começar outra torre
            v.push_back(x);
        } else {
            // caso contrario eu posso pensar que agora a posição em que inserir tem um cubo em cima de tamanho x
            v[k - v.begin()] = x;
        }
    }
    cout << v.size() << "\n";
    return 0;
}