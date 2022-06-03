#include <bits/stdc++.h>
using namespace std;

//força bruta puramente não passa pois é n^3
//a ideia é fazer força bruta em dois lados do triangulo e
//usar busca binária para achar as posições do tamanho máximo e
//do mínimo para o maior lado

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i<n; i++) for(int j = i+1; j<n; j++){//veja que j = i+1 para contar apenas triangulos diferentes
			int top = lower_bound(v.begin(), v.end(), v[i]+v[j])-v.begin();//
			ans+= top-(j+1);// o range de j+1 até top inclui todos as arestas que podem ser o maior lado 
	}
	cout << ans << '\n';
	return 0;
}