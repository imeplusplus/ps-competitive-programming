// Solution
// It's necessary to have a k such that a * b = k³
// a and b has to be multiple of k

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll a, b;

// Don't EVER check for integer numbers using sqrt() or cbrt()
// It would create imprecision, do it by binary search.
// We will put on the final test a question that will not work otherwise.
ll cubicFloor(ll x){
	// hi³ <= 1e18
	ll lo = 0, hi = 1e6;
	while(lo < hi){
		ll mid = (lo + hi) / 2;
		if(mid * mid * mid < x)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &a, &b);
		ll c = cubicFloor(a * b);
		if(c * c * c != a * b || a % c || b % c)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
