#include <bits/stdc++.h>
using namespace std;

int ans, n;

//a ideia é limpar uma linha, e dps contar quantas linhas estão limpas tb
//veja que pra cada linha, só existe uma maneira de torná-la limpa, assim só precisa testar 
//n jeitos de limpar o comôdo
//outra maneira de fazer isso é contando a maior quantidade de linhas iguais, codada no final

void flip_column(int c, vector<string>& room, vector<int>& cnt) {
    for (int i = 0; i < room.size(); i++) {
        if (room[i][c] == '1') room[i][c] == '0', cnt[i]--;
        else room[i][c] == '1', cnt[i]++;
    }
}

void clean_row(int r, vector<string> room, vector<int> cnt) {
    for (int i = 0; i < room.size(); i++) {
        if (room[r][i] == '1') flip_column(i, room, cnt);
    }
    int aux = 0;
    for (int i = 0; i < cnt.size(); i++) if (cnt[i] == 0) aux++;
    ans = max(ans, aux);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<string> room(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> room[i];
        for (char j : room[i]) if (j == '1') cnt[i]++;
    }
    for (int i = 0; i < n; i++) {
        clean_row(i, room, cnt);
    }
    cout << ans << '\n';
    return 0;
}

// int main(){
// 	cin.tie(NULL);
// 	ios_base::sync_with_stdio(false);
// 	cin >> n;
// 	vector<string> room(n);
// 	map<string, int> cnt;
// 	for(int i = 0; i<n; i++){
// 		cin >> room[i];
// 		cnt[room[i]]++;
// 	}
// 	for(int i = 0; i<n; i++){
// 		ans = max(ans, cnt[room[i]]);	
// 	}
// 	cout << ans << '\n';
// 	return 0;
// }
