#include <bits/stdc++.h>
using namespace std;


//usar um set para guardar as musicas tocadas e,
//dois ponteiros para guardar o começo e o fim do intervalo analisado
//anda com o pornteiro da direita adicionando musicas no set
//caso repita a musica, anda com o esquerdo até tirar a musica repetida, ou chegar no outro ponteiro
//a resposta é a maior diferenca na posição dos ponteiros, ou o tamanho do set


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, lo = 0, hi = 0, ans = 0;
	cin >> n;
	int k[n];	
	for(int i = 0; i<n; i++) cin >> k[i];
	set<int> s;
	while(hi<n){
		if(s.count(k[hi]) == 0){
			s.insert(k[hi]);
			hi++;
		} else {
			while(k[lo] != k[hi] and lo<hi){
				s.erase(k[lo]);
				lo++;
			}
			lo++;
			hi++;
		}
		ans = max(ans, hi-lo);
	}
	cout << ans << '\n';
	return 0;
}