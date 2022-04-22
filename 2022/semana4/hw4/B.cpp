// Solution
// Build 2 prefix-sums
// ps[0] for the original array
// ps[1] for the sorted array
// Atention for long long!

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, v[N], m, t, l, r;
long long ps[2][N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	
	// ps[0]
	for(int i = 0; i < n; i++)
		ps[0][i + 1] = ps[0][i] + v[i];
	
	//ps[1]
	sort(v, v + n);
	for(int i = 0; i < n; i++)
		ps[1][i + 1] = ps[1][i] + v[i];
		
	scanf("%d", &m);
	while(m--){
		scanf("%d %d %d", &t, &l, &r);
		printf("%lld\n", ps[t - 1][r] - ps[t - 1][l - 1]);
	}
	return 0;
}
