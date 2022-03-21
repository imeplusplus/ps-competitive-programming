#include <bits/stdc++.h>
using namespace std;


//a ideia é fazer um bubble sort e checar se a posição que ta trocando ta no vetor de p's
//ai pra checar rapido, usar busca binária

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
	return 0;
}