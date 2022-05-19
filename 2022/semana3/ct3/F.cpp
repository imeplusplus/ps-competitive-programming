// Tricky problem
// If we choose the numbers that are going to appear in the array, we'll already have the order fixed
// We have (2n - 1)! / [(n - 1)! * n!] possible set of n numbers between 1 and n
// Now we could order them in increasing or decreasing order, so we multiply it by 2
// Atention for the n cases where all elements are equal

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

// Fermat's Little Theorem for modular division
ll fexp(ll x, ll y){
	ll r = 1;
	while(y){
		if(y & 1)
			r = r * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return r;
}

ll ans, fat = 1;
int n;

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i < n; i++)
    	fat = fat * i % MOD;
    ans = fexp(fat, MOD - 2) * fexp(fat * n % MOD, MOD - 2) % MOD;
    
    for(int i = n; i < 2 * n; i++)
    	fat = fat * i % MOD;
    	
    ans = ans * fat * 2 % MOD;
    	
    // Take out intersection and watch out for negative values when dealing with MOD
    ans = (ans - n + MOD) % MOD;
    
    printf("%lld\n", ans);
    return 0;
}
