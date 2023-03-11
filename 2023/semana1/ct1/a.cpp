// complexidade do codigo: O(n^2) (O(nlogn) se usar não usar o bubble sort)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], trade[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        //inicializo vetor de trocas: 0 -> nao pode trocar, 1 -> pode trocar
        for (int i = 1; i <= n; i++) trade[i] = 0;
        //leitura
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            //marco que a troca entre x e x + 1 é possivel
            trade[x] = 1;
        }

        //bubble sort checando se posso realizar aquela troca
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j] > a[j + 1] and trade[j]) swap(a[j], a[j + 1]);
            }
        }
        bool ok = true;
        for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


//o vetor de trocas aumenta a memória usada mas deixa o código mais rápido
//porém busca binária também cabe nessa questao:
/*
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> n >> m;
        int a[n], p[m];
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<m; i++) cin >> p[i];
        sort(p, p+m);
        for(int i = 0; i<n; i++) for(int j = 0; j<n-1; j++){
            if(a[j]>a[j+1] and binary_search(p, p+m, j+1)) swap(a[j], a[j+1]);
        }
        bool ans = true;
        for(int i = 0; i<n-1; i++) if(a[i]>a[i+1]) ans = false;
        if(ans) cout << "YES\n";
        else cout << "NO\n";
        //da pra usar a função da biblioteca <algorithm> chamada is_sorted,
        //que checa se o vetor ta ordenado em ordem crescente
        // if(is_sorted(a, a+n)) cout << "YES\n";
        // else cout << "NO\n";
    }
    */