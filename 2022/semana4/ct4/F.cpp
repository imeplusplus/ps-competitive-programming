// Solution
// A variation of knapsack where O(N*W) is too large
// We change it in the following way
// #1: ks[i][j] = minimum weigth possible to have
// a sum of values = j with objects until i
// #2: ks[i][j] = min(ks[i - 1][j], ks[i - 1][j - v[i]] + w[i])
// That gives us O(N * maxValuePossible) = O(N * sumValues) = O(N² * Vmax)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e2 + 5;
const int V = 1e5 + 5;
const int INF = 1e9 + 5;

int v[N], n, ks[N][V], w[N], W, ans;

int main(){
	scanf("%d %d", &n, &W);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);
		
	// set ks[0][i] = INF and ks[0][0] = 0
	for(int i = 1; i < V; i++)
		ks[0][i] = INF;
		
	// build the knapsack
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < V; j++){
			if(j >= v[i])
				ks[i][j] = min(ks[i - 1][j], ks[i - 1][j - v[i]] + w[i]);
			else
				ks[i][j] = ks[i - 1][j];
		}
	
	// this knapsack doesn't retain the answer at ks[n][W]
	// we have to get the maximum j such that ks[n][j] <= W
	for(int j = 0; j < V; j++)
		if(ks[n][j] <= W)
			ans = j;
	
	printf("%d\n", ans);
	return 0;
}
