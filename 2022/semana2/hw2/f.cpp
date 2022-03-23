#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool check(vector<string> &b, int x, int y){
	if(b[x][y] == 'X') return false;
	//ve se tem torre ou parede abaixo
	for(int i = x+1; i<n; i++){
		if(b[i][y] == 'T') return false;
		if(b[i][y] == 'X') break;
	}
	//acima
	for(int i = x-1; i>=0; i--){
		if(b[i][y] == 'T') return false;
		if(b[i][y] == 'X') break;
	}
	//pra esquerda
	for(int i = y-1; i>=0; i--){
		if(b[x][i] == 'T') return false;
		if(b[x][i] == 'X') break;
	}
	//pra direita
	for(int i = y+1; i<n; i++){
		if(b[x][i] == 'T') return false;
		if(b[x][i] == 'X') break;
	}
	return true;
}

int count(vector<string> &b){
	int cnt = 0;
	for(string i: b) for(char j: i) if(j=='T') cnt++;
	return cnt;
}


void bt(vector<string> &b, int l, int c){
	if(c == n){
		ans = max(ans, count(b));
		return;
	}
	if(check(b, l, c)) b[l][c] = 'T';
	if(l != n-1) bt(b, l+1, c);
	else bt(b, 0, c+1);
	if(b[l][c] == 'T'){
		b[l][c] = '.';
		if(l != n-1) bt(b, l+1, c);
		else bt(b, 0, c+1);
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while(true){
		cin >> n; //n e ans declarados globalmente
		ans = 0;
		if(n == 0) break;
		vector<string> board(n);
		for(int i = 0; i<n; i++) cin >> board[i];
		bt(board, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}