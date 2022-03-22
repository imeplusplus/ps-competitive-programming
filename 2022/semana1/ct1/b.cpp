#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int a[N], trade[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, int> number;
    int pos1 = -1, pos2 = -1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        //busca k - x
        if(number.count(k - x)){
            //existe resposta
            pos1 = i;
            pos2 = number[k - x];
        }
        //insere no map
        number[x] = i;
    }
    //verifica se achou resposta
    if(pos1 == -1) cout << "-1\n";
    else cout << pos1 << " " << pos2 << "\n";
    return 0;
}