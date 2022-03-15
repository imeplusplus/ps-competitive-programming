#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n, v[1000], cnt[N];

//questao boa para praticar counting sort pq os numeros vão até 1e6;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> v[i];
		cnt[v[i]]++;
	}
	int ord_v[1000];
	for(int i = 0, pos = 0; i<=1e6; i++){
		while(cnt[i]){
			ord_v[pos] = i;
			pos++;
			cnt[i]--;
		}
	}
	cout << ord_v[(n-1)/2] << '\n';
	return 0;
}