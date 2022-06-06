// Go with x = [1, k] and sum the concatenation of x and rev(x)
// Careful with overflow

#include<bits/stdc++.h>
using namespace std;

int main(){
	int k, p;
	long long ans = 0;
	scanf("%d %d", &k, &p);
	for(int i = 1; i <= k; i++){
		long long sum = i, aux = i, rev = 0;
		while(aux){
			rev = rev * 10 + aux % 10;
			sum = 10 * sum % p;
			aux /= 10;
		}
		ans = (ans + sum + rev) % p;
	}
	printf("%lld\n", ans);
	return 0;
}
