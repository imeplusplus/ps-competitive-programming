#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string s;
bool fim[N];
int trie[N][10], nxt;

// if you don't know trie, ask for help
// add + qry at the same tame (pro move)
bool add_qry(int node = 0, int pos = 0){
	// s has some previous number as prefix
	if(fim[node])
		return false;
		
	if(pos == s.size()){
		// s is prefix of a previous number
		if(node != nxt)
			return false;
		
		return fim[node] = true;
	}
		
	if(!trie[node][s[pos] - '0'])
		trie[node][s[pos] - '0'] = ++nxt;
	return add_qry(trie[node][s[pos] - '0'], pos + 1);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		bool ans = true;
		cin >> n;
		while(n--){
			cin >> s;
			ans &= add_qry();
		}
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
			
		// reset trie;
		for(int i = 0; i <= nxt; i++){
			fim[i] = false;
			for(int j = 0; j < 10; j++)
				trie[i][j] = 0;
		}
		nxt = 0;
	}
	return 0;
}
