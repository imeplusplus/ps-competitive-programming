#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		cin >> n;
		while(n>=2){
			int pir = 0, last_pir = 0;
			for(int i = 1; pir <= n; i++){
				last_pir = pir;
				pir = last_pir + 2*(i) + i-1;
			}
			n -= last_pir;
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}