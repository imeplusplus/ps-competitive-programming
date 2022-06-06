// Attention for presentation!!!

#include<bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;

int trie[N][2], nxt, s, fim[N];

// if you don't know trie, ask for help
// bits trie, transform the number in a bit string
void add(int i, int node = 0, int pos = 31){
	if(pos < 0){
		if(!fim[node])
			fim[node] = i;
		return;
	}
	
	if(!trie[node][(s >> pos) & 1])
		trie[node][(s >> pos) & 1] = ++nxt;
	add(i, trie[node][(s >> pos) & 1], pos - 1);
}

// Greatest xor is trying to get the opposite bit
int qry(int node = 0, int pos = 31){
	if(pos < 0)
		return fim[node];
	
	if(trie[node][1 ^ (s >> pos) & 1])
		return qry(trie[node][1 ^ (s >> pos) & 1], pos - 1);
	
	// If there's no number in this route with the opposite bit, go through the same bit
	return qry(trie[node][(s >> pos) & 1], pos - 1);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> s;
			add(i);
		}
		while(m--){
			cin >> s;
			cout << qry() << "\n";
		}
		
		// Presentation
		cout << '\n';
		
		// reset trie
		for(int i = 0; i <= nxt; i++)
			trie[i][0] = trie[i][1] = fim[i] = 0;
		nxt = 0;
	}
	return 0;
}
