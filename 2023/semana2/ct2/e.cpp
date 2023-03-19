#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		//como a está elevado ao quadrado na fórmula dada e n vai até 1e9, a só precisa ir até 1e(4,5)
		for(int i = 3; i*i<=2*n-1; i+=2){
			//cria as outras variáveis pra ver se também vale pitágoras
			int b = ((i*i)-1)/2;
			int c = b+1;
			if((i*i) + (b*b) == (c*c)) ans++;
		}
		//se perceber a matemática da questão:
		//for(int i = 3; i*i < 2*n+1; i+=2) ans++;
		cout << ans << '\n';
		ans = 0;
	}
}