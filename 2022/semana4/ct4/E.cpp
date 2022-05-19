// Solution
// Every t mod (c + 1) has the same brightness to the stars
// Do c + 1 2d-prefix sums
// Atention for stars at the same position

#include<bits/stdc++.h>
using namespace std;

const int C = 15;
const int N = 1e2 + 5;

int ps[C][N][N], n, q, c, t, x, y, s, xinf, yinf, xsup, ysup;

int main(){
	scanf("%d %d %d", &n, &q, &c);
	while(n--){
		scanf("%d %d %d", &x, &y, &s);
		for(int i = 0; i <= c; i++)
			ps[i][x][y] += (s + i) % (c + 1);
	}
	
	// Build the prefix sum
	for(int i = 0; i <= c; i++)
		for(int j = 1; j < N; j++)
			for(int k = 1; k < N; k++)
				ps[i][j][k] += ps[i][j - 1][k]
				             + ps[i][j][k - 1]
				             - ps[i][j - 1][k - 1];
	
	// Queries
	while(q--){
		scanf("%d %d %d %d %d", &t, &xinf, &yinf, &xsup, &ysup);
		printf("%d\n", ps[t % (c + 1)][xsup][ysup]
		             - ps[t % (c + 1)][xinf - 1][ysup]
					 - ps[t % (c + 1)][xsup][yinf - 1]
					 + ps[t % (c + 1)][xinf - 1][yinf - 1]);
	}
	return 0;
}
