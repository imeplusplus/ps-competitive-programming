// You could use some smart algorithms to get a fast solution
// ... or you could brute force it

#include<bits/stdc++.h>
using namespace std;

string s;
set<string> ss;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	ss.insert(s);
	for(int i = 1; i < s.size(); i++)
		ss.insert(s.substr(i) + s.substr(0, i));
	cout << ss.size();
	return 0;
}
