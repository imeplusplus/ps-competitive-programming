#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, t;

int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", (n - 1) / 2);
	}
	return 0;
}
