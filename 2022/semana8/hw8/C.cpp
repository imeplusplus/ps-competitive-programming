#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

string s, fim[N];
int trie[N][30], nxt;

// if you don't know trie, ask for help
void add(int node = 0, int pos = 0){
	if(pos == s.size())
		fim[node] = s + '\n';
	else{
		if(!trie[node][s[pos] - 'a'])
			trie[node][s[pos] - 'a'] = ++nxt;
		add(trie[node][s[pos] - 'a'], pos + 1);
	}
}

// bool to treat the "No match." case
bool qry(int node = 0, int pos = 0){
	if(pos > s.size())
		cout << fim[node];
	
	// If s is already the prefix of this node, go through every route onwards
	if(pos >= s.size()){
		// Notice that it already prints the strings in lexicographical order
		for(int i = 0; i < 30; i++)
			if(trie[node][i])
				qry(trie[node][i], pos + 1);
		return true;
	}
	else{
		if(trie[node][s[pos] - 'a'])
			return qry(trie[node][s[pos] - 'a'], pos + 1);
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		add();
	}
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> s;
		cout << "Case #" << tt << ":\n";
		if(!qry())
			cout << "No match.\n";
	}
	return 0;
}
