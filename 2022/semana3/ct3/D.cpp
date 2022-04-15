// Solution
// #1: Use sieve to get the number of primes in the factorization of each number until 1e6
// #2: Create a vector for each "factorful"
// #3: Get the answer by binary search of a and b on v[n]

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, a, b, primeFactors[N];
vector<int> v[11];

void sieve(){
	for(int i = 2; i < N; i++){
    	if(primeFactors[i])
			continue;
		// Can't use the i * i optimization
    	for(int j = i; j < N; j += i)
			primeFactors[j]++;
	}
}

int main(){
	sieve();
    for(int i = 1; i < N; i++)
    	if(primeFactors[i] <= 10)
    		v[primeFactors[i]].push_back(i);
    
    scanf("%d", &t);
    while(t--){
    	scanf("%d %d %d", &a, &b, &n);
    	printf("%d\n", upper_bound(v[n].begin(), v[n].end(), b) - lower_bound(v[n].begin(), v[n].end(), a));
	}
    return 0;
}
