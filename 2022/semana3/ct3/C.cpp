// lcm(a, b) / a = b / gcd(a, b)
// 'a' pass through every value
// gcd(a, b) pass through every divisor of b
// Answer = #divisors(b)

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll b, ans;

int main(){
    scanf("%lld", &b);
    for(ll i = 1; i * i <= b; i++){
    	if(b % i)
    		continue;
    	ans++;
    	if(i != b / i)
    		ans++;
	}
    printf("%lld\n", ans);
    return 0;
}
