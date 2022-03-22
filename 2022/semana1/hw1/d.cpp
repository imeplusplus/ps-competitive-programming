#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	map<pair<int, int>, string> m;
	for(int i = 0; i < t; i++){
		int a, b;
		string s;
		cin >> a >> b >> s;
		if(m.find({a, b}) == m.end()) m.insert({make_pair(a, b), s});
		else m[{a, b}] = s;
		// eh possivel escrever da forma abaixo:
		// if(m.count({a, b})) m[{a, b}] = s;
		// else m.insert({{a, b}, s});
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		int a, b;
		cin >> a >> b;
		cout << m[{a, b}] << '\n';
	}
	return 0;
}