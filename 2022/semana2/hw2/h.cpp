//@xixo
#include <bits/stdc++.h>
using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	vector<int> shells(3);
	cin >> n >> x;
	shells[x] = 1;
	//veja que depois de 6 jogadas, os movimentos repetem, então basta fazer n%6 jogadas
	n = n%6;
	while(n--){
		if(n&1) swap(shells[1], shells[2]);
		else swap(shells[1], shells[0]);
	}
	for(int i = 0; i<3; i++) if(shells[i]){
		cout << i <<'\n';
	}
	return 0;
}