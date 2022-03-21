#include <bits/stdc++.h>
using namespace std;

//para que o número seja o maior possivel, basta deletar o primeiro zero
//caso não tenha zero, deleta qualquer "1"

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0; i<s.size(); i++) if(s[i] == '0'){
		//na primeira vez que acha um zero 
		//printa a soma da string de 0 até i-1 mais a string de i+1 até o fim
		cout << s.substr(0, i) + s.substr(i+1, s.size()-i+1) << '\n';
		return 0;
	}
	cout << s.substr(0, s.size()-1) << '\n';
	return 0;
}