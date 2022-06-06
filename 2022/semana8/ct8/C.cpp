// BIT

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

ll bt[N];

void add(int pos, ll val){
	while(pos < N){
		bt[pos] += val;
		pos += pos & -pos;
	}
}

int qry(int pos){
	ll r = 0;
	while(pos){
		r += bt[pos];
		pos -= pos & -pos;
	}
	return r;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	while(q--){
		char s[5];
		scanf(" %s", &s);
		if(s[0] == 'f'){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", qry(b) - qry(a - 1));
		}
		else{
			int a;
			ll val;
			scanf("%d %lld", &a, &val);
			add(a, val);
		}
	}
	return 0;
}
