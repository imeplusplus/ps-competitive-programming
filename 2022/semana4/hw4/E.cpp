// Solution
// #1: dp[i] = minimum cost to go from position 1 to position i
// #2: dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
//  	            dp[i - 2] + abs(h[i] - h[i - 2]));

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, h[N], dp[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; i++)
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
		            dp[i - 2] + abs(h[i] - h[i - 2]));
	printf("%d\n", dp[n - 1]);
	return 0;
}
