// Solution
// Coul build a 1-indexed prefix sum
// min_sum = min(ps[i] - ps[i - k - 1]) for 1 <= i <= N

// Just as kadane, could also skip the prefix sum
// The idea for this problem is called "sliding window"
// Take the sum of a "window" of length k
// than "slide" it through the array

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, h[N], min_sum, ans, cur;

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &h[i]);
		
	// Get the sum of the first "window"
	for(int i = 0; i < k; i++)
		cur += h[i];
	min_sum = cur;
	
	// "Slide" the "window" through the array
	for(int i = k; i < n; i++){
		// 1 adition and 1 subtraction to "slide" it
		cur += h[i] - h[i - k];
		if(cur < min_sum){
			min_sum = cur;
			ans = i - k + 1;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
