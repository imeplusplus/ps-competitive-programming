// Kadane
// Attention for the corner case of all negative values
// Empty substring is not valid

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x, ans = -1e9, curr;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%lld", &x);
		curr += x;
		ans = max(ans, curr);
		curr = max(curr, 0ll);
	}
	printf("%lld\n", ans);
	return 0;
}