// DP
// dp[i][j] = number of ways to have the first i statements
// havint the i-th statement (indexed by 1) with j 'tabs' of identation

// a[i - 1] = f -> dp[i][j] = dp[i - 1][j - 1]
// a[i - 1] != f -> dp[i][j] = sum(dp[i - 1][k]), k >= j -> dp[i][j] = dp[i][j + 1] + dp[i - 1][j]
// (as long as the previoues statemente has k of identation, we can get to j)
// If you calculate the sum for each state of the dp it will give a TLE verdict

// Now let's do this iterative and optmizing memory :)
// (you don't have to do this optimizations)
#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

char c;
int n, dp[N], s;

// If you don't understand this solution, try the recursive solution with 2 dimensions to the dp first
int main(){
	scanf("%d", &n);
	dp[0] = 1;
	
	// Yes, I'm ignoring the last input
	for(int i = 1; i < n; i++){
		scanf(" %c", &c);
		if(c == 'f'){
			for(int j = N - 1; j; j--)
				dp[j] = dp[j - 1];
			dp[0] = 0;
		}
		else
			for(int j = N - 2; j >= 0; j--)
				dp[j] = (dp[j] + dp[j + 1]) % MOD;
	}
	for(int i = 0; i < N; i++)
		s = (s + dp[i]) % MOD;
	printf("%d\n", s);
	return 0;
}
