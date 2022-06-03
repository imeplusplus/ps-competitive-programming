//@xixo
#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i<n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	//n<=3e3 entao n^2*logn passa tranquilo
	for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) if(i!=j){
		//sejam X e Y dois vetores de v
		//seja Z = X+(X-Y) = 2*X-Y. Se Z pertence à v, entao X é ponto médio de Y e Z
		pair<int, int> p = {2*v[i].first, 2*v[i].second};
		p.first-=v[j].first;
		p.second-=v[j].second;
		if(binary_search(v.begin(), v.end(), p)){
			ans++;
		}
	}
	//essa solução conta duas vezes a resposta entao printa dividindo por dois
	cout << ans/2 << "\n";
	return 0;
}