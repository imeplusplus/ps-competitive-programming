// #divisors(x) = product(e_i + 1), where e_i are the exponents in the factorization of x
// #divisors(x) = 3 when e_j = 2 for some j and e_i = 0 for every other
// Thus, for x to be a T prime, x has to be the quadratic of a prime

// Solution (O(constant) = O(1), I'm just being didactic)
// #1: Use sieve to get every prime until 1e6 in O(1e6log(log(1e6))) = O(5e6)
// #2: For every prime you store it's quadratic in a set in O(1e6log(1e6)) = O(2e7)
// These is going to store every T prime until 1e12 (1e6 * 1e6)
// #3: For each of the n <= 1e5 queries that follows, check if x is in our set in O(1e5*log(1e6)) = O(2e6)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int n;
ll x;
bool composite[N];
set<ll> t_primes;

void sieve(){
	for(ll i = 2; i < N; i++){
    	if(composite[i])
			continue;
    	for(ll j = i * i; j < N; j += i)
			composite[j] = true;
			
		// Only line that differs from normal sieve.
		t_primes.insert(i * i);
	}
}

int main(){
	sieve();
    
    scanf("%d", &n);
    while(n--){
    	scanf("%lld", &x);
    	if(t_primes.find(x) == t_primes.end())
			printf("NO\n");
    	else
			printf("YES\n");
	}
    return 0;
}
