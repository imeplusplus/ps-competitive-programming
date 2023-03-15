#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int songs[N], n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> songs[i];

    //two pointers
    set<int> unique_songs;
    int ans = 0;
    //for: calcula a maior sequencia que termina na posicao r
    for(int l = 0, r = 0; r < n; r++){
        /*
            tento colocar a musica da posição r
            enquanto aquela musica existir no set, nao posso inserir
            removo a musica da posicao l
            ando com ponteiro l
        */
        while(unique_songs.count(songs[r])){
            unique_songs.erase(songs[l]);
            l++;
        }
        unique_songs.insert(songs[r]);
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}
