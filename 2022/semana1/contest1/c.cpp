#include <bits/stdc++.h>
using namespace std;

//usar o valor do vetor dado como posição no vetor resposta e a posição como valor

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int v[n], ans[n];
	for(int i = 0; i<n; i++){
		cin >> v[i];
		ans[v[i]-1] = i+1;
	}
	for(int i = 0; i<n; i++) cout << ans[i] << " ";
	cout << '\n';
	return 0;
}