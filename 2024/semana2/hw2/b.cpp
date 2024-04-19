//@xixo
#include <bits/stdc++.h>
using namespace std;

//soluções inteiras para a eq:
//k_a*a + k_b*b + k_c*c = n

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c, n, ans = 0;
	cin >> n >> a >> b >> c;
	//como n, a, b e c são todos <=4000
	//a solução de força bruta tem complexidade O(n^2)
	for(int i = 0; i*a<=n; i++) for(int j = 0; i*a+j*b<=n; j++){
		//com dois coeficientes, o terceiro está fixo
		int k = n - (i*a) - (j*b);
		//porém, k = K_c*c, então é necessario checar se k é multiplo de c
		//caso verdade, a resposta é atualizada 
		if(k%c == 0){
			k/=c;
			ans = max(ans, i+j+k);
		}
	}
	cout << ans << '\n';
	return 0;
}
