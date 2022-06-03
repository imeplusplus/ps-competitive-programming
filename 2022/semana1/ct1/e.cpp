#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, q, x[N], m;

//com m moedas, é possivel comprar qualquer beecola que custe m ou menos
//logo a resposta é a ultima posição cujo valor seja <= à m 
//é possível codar uma busca binária para tal, como comentado abaixo, mas
//a posição anterior ao retorno do upper_bound dá a mesma resposta

// int b_search(int l, int r, int v){
// 	int mid = (l+r)/2;
// 	while(l<r){
// 		if(x[mid] > v) r = mid-1;
// 		else l = mid;
// 	}
//	return mid;
// }

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x, x + n);
	cin >> q;
	while (q--) {
		cin >> m;
		cout << upper_bound(x, x + n, m) - x << '\n';
	}
	return 0;
}