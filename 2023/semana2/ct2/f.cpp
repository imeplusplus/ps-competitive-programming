#include <bits/stdc++.h>
using namespace std;

//questao de backtracking
//atenção ao bizu da matriz blocks senão fica HORROROSO de codar o check

bool solved = false;
int board[9][9];
bool blocks[3][3][10];

bool check(int l, int c, int v){
	for(int i = 0; i<9; i++) if(i!=l and board[i][c] == v) return false; // checa a coluna
	for(int i = 0; i<9; i++) if(i!=c and board[l][i] == v) return false; // checa a linha
	//checa o bloco:
	return !blocks[l/3][c/3][v];
}

void bt(int l, int c){
	if(c==9){
		solved = true;
		for(int i = 0; i<9; i++){
			for(int j = 0; j<9; j++) cout << board[i][j] << " ";
			cout << '\n';
		}
		return;
	}
	if(board[l][c]){
		if(l == 8) bt(0, c+1);
		else bt(l+1, c);
	} else for(int i = 1; i<=9; i++) if(check(l, c, i)){
		board[l][c] = i;
		blocks[l/3][c/3][i] = true;
		if(l == 8) bt(0, c+1);
		else bt(l+1, c);
		blocks[l/3][c/3][i] = false;
		board[l][c] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--){
		memset(blocks, 0, sizeof blocks);
		for(int i = 0; i<9; i++) for(int j = 0; j<9; j++){
			cin >> board[i][j];
			blocks[i/3][j/3][board[i][j]] = true;		
		}
		solved = false;
		bt(0, 0);
		if(not solved) cout << "No solution\n";
	}
	
	return 0;
}