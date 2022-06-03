#include <bits/stdc++.h>
using namespace std;

string friends[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int ans;
	for(int i = 0; i<s.size(); i++){
		for(int j = 0; j<5; j++){
			string aux = s.substr(i, friends[j].size());
			if(aux == friends[j]) ans++;
		}
	}
	if(ans == 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}