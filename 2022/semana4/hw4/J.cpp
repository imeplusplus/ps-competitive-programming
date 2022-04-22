// Solution
// There are 6 rotations for each block
// Since there are as many block as we want,
// let's consider each rotation as a different block
// Now we do similar to LIS with this 6N blocks,
// where we check for x[i] < x[j] AND z[i] < z[j]
// doesn't check for j < i
// and each block has a value of y[i]
// So dp[i] = max(dp[j]) + y[i] for x[i] < x[j] AND z[i] < z[j]
// Since there is no clear "direction" for the dp, let's do memoization

#include<bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

// Let's remember how struct works
struct block{
	int x, y, z;
	
	// This is needed to create a block with the values we want
	// The "_x = 0" gives a default value for the variable
	// if we don't specify the values we want
	// The ": x(_x)" makes "x = _x" faster
	block(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z){}
	
	// This kind of function change how an operator works
	bool operator <(block o){
		return x < o.x && z < o.z;
	}
};

int n, x, y, z, dp[N], ans, vis[N], h;
block b[N];

int calc(int i){
	// When we have to do a lot of tests, this is a way to
	// not have to reset the vis[N], we simply increase h
	// and check for vis[i] == h
	if(vis[i] == h)
		return dp[i];
	dp[i] = 0;
	for(int j = 0; j < 6 * n; j++)
		if(b[i] < b[j])
			dp[i] = max(dp[i], calc(j));
	dp[i] += b[i].y;
	vis[i] = h;
	return dp[i];
}

int main(){
	scanf("%d", &n);
	while(n){
		ans = 0;
		h++;
		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &x, &y, &z);
			b[6 * i + 0] = block(x, y, z);
			b[6 * i + 1] = block(y, x, z);
			b[6 * i + 2] = block(x, z, y);
			b[6 * i + 3] = block(y, z, x);
			b[6 * i + 4] = block(z, y, x);
			b[6 * i + 5] = block(z, x, y);
		}
		for(int i = 0; i < 6 * n; i++)
			ans = max(ans, calc(i));
		printf("%d\n", ans);
		scanf("%d", &n);
	}
	return 0;
}
