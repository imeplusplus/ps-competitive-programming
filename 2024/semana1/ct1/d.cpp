// complexidade dos dois códigos: O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int f[n];
    //set de quem falta receber, e quem falta dar
    set<int> giv, rec;
    //primeiro todo mundo falta receber. Conforme vai lendo, apaga quem recebeu
    for (int i = 0; i < n; i++) rec.insert(i + 1);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        if (f[i] == 0) giv.insert(i + 1);
        rec.erase(f[i]);
    }
    //primeiro, acha quem ta isolado(não recebeu nem deu ainda) e faz ele dar pra alguem que tb tá isolado
    set<int> isolated;
    for (auto i = giv.begin(); i != giv.end(); i++) if (rec.count(*i)) isolated.insert(*i);
    while (isolated.size() > 1) {
        auto a = isolated.begin();
        auto b = a;
        b++;
        f[(*a) - 1] = *b;
        giv.erase(*a);
        isolated.erase(a);
        rec.erase(*b);
        isolated.erase(b);
    }
    //se ainda tiver alguem isolado, faz dar pra alguem que não si msm
    if (isolated.size()) {
        auto a = isolated.begin();
        auto b = rec.begin();
        if (*a == *b) b++;
        f[(*a) - 1] = *b;
        giv.erase(*a);
        rec.erase(*b);
        isolated.erase(a);
    }
    //agora, como é impossivel se dar um presente, basta dar pra alguem que não recebeu ainda
    while (!giv.empty()) {
        auto aux = giv.begin();
        auto aux1 = rec.begin();
        f[(*aux) - 1] = *aux1;
        giv.erase(aux);
        rec.erase(aux1);
    }
    for (int i = 0; i < n; i++) cout << f[i] << " ";
    cout << '\n';
    return 0;
}


// segunda solução

/*

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), pos;
    set<int> s;
    // vou inserir todos os numeros num set para manter conta do que resta ou não
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        // separo nos que já sei e nos que são zero
        if(!v[i]) {
            pos.push_back(i);
        } else {
            s.erase(v[i]);
        }
    }
    auto it = s.begin();
    // gulosamente insiro os que restam no vetor
    for(int i = 0; i < pos.size(); i++) {
        v[pos[i]] = *it;
        it++;
    }
    for(int i = 0; i < n; i++) {
        // se por acaso der conflito, eu posso rapidamente fazer uma troca para evitar isso
        if(v[i] == i + 1) {
            for(int j = 0; j < pos.size(); j++) {
                if(v[pos[j]] != i + 1) {
                    swap(v[i], v[pos[j]]);
                    break;
                }
            }
        }
    }
    for(auto e : v) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}

*/
