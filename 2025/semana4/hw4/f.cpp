// DSU

#include<bits/stdc++.h>
using namespace std;

int t, n;
map<string, string> father;
map<string, int> size;

string find(string s){
	if(father.find(s) == father.end())
		return s;
	return father[s] = find(father[s]);
}

void join(string s1, string s2){
	s1 = find(s1);
	s2 = find(s2);
	if(s1 == s2)
		return;
	if(size[s1] < size[s2])
		swap(s1, s2);
	size[s1] += size[s2];
	father[s2] = s1;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while(t--){
		father.clear();
		size.clear();
		cin >> n;
		while(n--){
			string s1, s2;
			cin >> s1 >> s2;
			
			// size = 1 if it's the first appearence of the string
			size[s1] = max(1, size[s1]);
			size[s2] = max(1, size[s2]);
			
			join(s1, s2);
			cout << size[find(s1)] << '\n';
		}
	}
	return 0;
}
