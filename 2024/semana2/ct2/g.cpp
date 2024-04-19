#include <bits/stdc++.h>
using namespace std;

//nessa questão funciona tb codar o jogo, mas da pra perceber que não precisa e tem apenas 4 casos

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	if(a>b) cout << "Takahashi\n";
	else if(b>a) cout << "Aoki\n";
	else if(c==0) cout << "Aoki\n";
	else cout << "Takahashi\n";
	return 0;
}
