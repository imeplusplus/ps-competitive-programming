// Read the solution for the easier version
// Same idea with binary search over the answer
// O(check solution * log(ans)) = O(N * log(a_max + K))

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n;
ll mp, a[N], b[N];

bool val(ll cookies){
	ll mp_needed = 0;
	for(int i = 0; i < n; i++){
		mp_needed += max(0ll, a[i] * cookies - b[i]);
		
		// We need this to avoid overflow
		if(mp_needed > mp)
			return false;
	}
	return true;
}

ll binS(){
	// hi = a_max + K
	ll lo = 0, hi = 2e9;
	while(lo < hi){
		// Atention for +1 in binary search problems
		// lo = mid + 1 -> mid = (lo + hi) / 2
		// hi = mid - 1 -> mid = (lo + hi + 1) / 2
		ll mid = (lo + hi + 1) / 2;
		if(val(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

int main(){
	scanf("%d %lld", &n, &mp);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	printf("%lld\n", binS());
	return 0;
}
