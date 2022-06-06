// Tricky problem
// KMP will get us O(N * Q) = 1.5e9, TLE

// Solution: Trie adding all N suffixes of the professors string
// O(N² + Q) = 1e7

#include<bits/stdc++.h>
using namespace std;

const int N = 5e6;

string s;
int trie[N][30], nxt, fim[N];

void add(int node = 0, int pos = 0){
	// # suffixes that pass through this node
	// = # substrings equal to the prefix of this suffix
	fim[node]++;
	
	if(pos == s.size())
		return;
	if(!trie[node][s[pos] - 'a'])
		trie[node][s[pos] - 'a'] = ++nxt;
	add(trie[node][s[pos] - 'a'], pos + 1);
}

int qry(int node = 0, int pos = 0){
	if(pos == s.size())
		return fim[node];
	if(!trie[node][s[pos] - 'a'])
		return 0;
	return qry(trie[node][s[pos] - 'a'], pos + 1);
}

int main(){
	// Without this line you get TLE
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, q;
	cin >> n >> q;
	string p;
	cin >> p;
	for(int i = 0; i < p.size(); i++){
		s = p.substr(i);
		add();
	}
	while(q--){
		cin >> s;
		cout << qry() << '\n';
	}
	return 0;
}
