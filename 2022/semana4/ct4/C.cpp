// Solution
// Kadane, checking for when a[i] < a[i - 1] instead of sum < 0

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, ans, cur, a[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n + 1; i++){
		if(a[i] < a[i - 1])
			cur = 0;
		cur++;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}
