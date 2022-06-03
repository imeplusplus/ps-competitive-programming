#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int v[100];
	for(int i = 0; i < n; i++) cin >> v[i];
	//não é necessário usar bubble sort, mas é bom praticar nessa questao pq n<=100;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){
			if(v[j] > v[j+1]) swap(v[j], v[j+1]);
		}
	}
	int pos = 1;
	while(v[pos] == v[pos-1] and pos<n) pos++;
	if(pos!=n) cout << v[pos] << '\n';
	else cout << "NO\n";
	return 0;
}