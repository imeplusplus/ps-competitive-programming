//@xixo
#include <bits/stdc++.h>
using namespace std;

//vetor q salva todas as soluções pra não ter q calcular td dnv para diferentes queries
//cada solução vai ser salva como um vetor de tamanho 8, onde cada posição guarda a linha
//da rainha que está na i-ésima coluna
vector<vector<int>> solutions;

bool check(vector<int> &v, int c, int l){
	//função que checa se pode botar uma rainha na posição c, l
	//compara com as rainhas colocadas ate a coluna c-1;
	for(int i = 0; i < c; i++){
		//checa a linha
		if(v[i] == l) return false;
		//checa a diagonal
		if(abs(c-i) == abs(v[i]-l)) return false;
	}
	return true;
}

void bt(vector<int> &cur, int c){
	if(c == 8){
		//se chegou aqui, é pq preencheu todo o tabuleiro
		//então salva no vetor soluções
		solutions.push_back(cur);
		return;
	}
	for(int i = 0; i<8; i++){
		if(check(cur, c, i)){
			cur[c] = i;
			bt(cur, c+1);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> board(8);
	//chama o backtracking no começo para gerar todas as soluções
	bt(board, 0);
	int t;
	cin >> t;
	while(t--){
		cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
		int x, y;
		cin >> x >> y;
		int sol_cnt = 1;
		for(auto i: solutions){
			//o problema é conhecido e sabe-se que existem 92 soluções para ele
			//portando iterar pelo vetor soluções não é ruim
			if(i[y-1] == x-1){
				if(sol_cnt > 1) cout << '\n';
				cout << setw(2) << sol_cnt;
				cout << "     ";
				for(int j: i) cout << " " << j+1;
				sol_cnt++;
			}
		}
		if (t) cout << "\n\n";
	}
	cout << '\n';
	return 0;
}


//eu odeio o jeito q tem q printar essa questão. aqui embaixo ta um jeito melhor de ler o while:
/*
	while(t--){
		int x, y;
		cin >> x >> y;
		for(auto i: solutions){
			//o problema é conhecido e sabe-se que existem 92 soluções para ele
			//portando iterar pelo vetor soluções não é ruim
			if(i[y-1] == x-1){
				for(int j: i) cout << " " << j+1;
				cout << '\n';
			}
		}
		cout << '\n';
	}
*/