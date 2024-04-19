#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	bool ans = true;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(!(i & 1) and isupper(s[i])) ans = false; // isupper checa se o char é maiusculo
		if((i & 1) and islower(s[i])) ans = false;// islower checa se o char é minúsculo
		//são funções da biblioteca cctype
	}
	if(ans) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
