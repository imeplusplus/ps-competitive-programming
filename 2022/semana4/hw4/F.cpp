// Solution
// Knapsack
// Extra: Memory Optimization

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int ks[N][N], w[N], v[N], W, n;

int main(){
	scanf("%d %d", &W, &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= W; j++){
			if(j >= w[i])
				ks[i][j] = max(ks[i - 1][j], ks[i - 1][j - w[i]] + v[i]);
			else
				ks[i][j] = ks[i - 1][j];
		}
	printf("%d\n", ks[n][W]);
	return 0;
}
