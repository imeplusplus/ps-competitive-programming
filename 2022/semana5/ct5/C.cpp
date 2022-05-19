// There are better solutions, but O(t * n²) sufices
// So just follow the problem instructions

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int t, n, a[N], d[N];

void calcDepth(int depth, int lo, int hi){
	// Get the index of the maximum a[ma] in the range [lo, hi]
	int ma = 0;
	for(int i = lo; i <= hi; i++)
		if(a[i] > a[ma])
			ma = i;
		
	// If not empty, split the range for the children
	if(ma != 0){
		d[ma] = depth;
		
		// left child
		calcDepth(depth + 1, lo, ma - 1);
		
		// right child
		calcDepth(depth + 1, ma + 1, hi);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		calcDepth(0, 1, n);
		for(int i = 1; i < n; i++)
			printf("%d ", d[i]);
		printf("%d\n", d[n]);
	}
}
