#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long fexp(long long b, long long e, long long m = MOD){
	long long ans = 1;
    while(e){
        if(e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e /= 2;
    }
    return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		cout << fexp(a, b, c) << '\n';
	}
	//por algum motivo tem um zero no fim do input e precisa ler pra n dar TLE
	cin >> t;
	return 0;
}