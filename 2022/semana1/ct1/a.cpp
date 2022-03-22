#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int a[N], trade[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        //inicializo vetor de trocas: 0 -> nao pode trocar, 1 -> pode trocar
        for(int i = 1; i <= n; i++) trade[i] = 0;
        //leitura
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            //marco que a troca entre x e x + 1 é possivel
            trade[x] = 1;
        }

        //bubble sort checando se posso realizar aquela troca
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(a[j] > a[j + 1] and trade[j]) swap(a[j], a[j + 1]);
            }
        }
        bool ok = true;
        for(int i = 1; i < n; i++) if(a[i] > a[i + 1]) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}