#include <bits/stdc++.h>
using namespace std;

//a ideia é guardar os numeros num array de pair, tal que o first é o valor
//e o second é a posição original do valor. Desse modo, ao ordenar para fazer a busca binária,
//é possivel resgatar a posição original do valor

const int N = 2e5+5;

int n, x;
pair<int, int> v[N];

int b_srch(int l, int r, int val){
	int mid = (l+r)/2;
	while(l<r){
		if(v[mid].first < val) l = mid+1;
		else r = mid;
		mid = (l+r)/2;
	}
	return mid;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	for(int i = 0; i<n; i++){
		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(v, v+n);
	for(int i = 0; i<n-1; i++){
		//é possivel usar o lower_bound(). Lembrando que ela retorna um PONTEIRO
		//auto aux = lower_bound(v+i+1, v+n, make_pair(x-v[i].first, 0));
		int aux = b_srch(i+1, n-1, x-v[i].first);
		if((v[i].first + v[aux].first == x)){ // ou: v[i].first + (*aux).first == x
			cout << v[i].second << " " << v[aux].second << '\n';
			//cout << v[i].second << " " << (*aux).second << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}