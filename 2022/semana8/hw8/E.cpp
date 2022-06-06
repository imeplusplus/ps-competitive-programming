#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;

string s, fim[N];
int trie[N][30], nxt, mrw[N], this_node[N];

// if you don't know trie, ask for help
// to get the optimal route later, each node have
// the number of most repeated words this node onwards
int add(int node = 0, int pos = 0){
	if(pos == s.size()){
		fim[node] = s;
		return mrw[node] = max(++this_node[node], mrw[node]);
	}
	
	if(!trie[node][s[pos] - 'a'])
		trie[node][s[pos] - 'a'] = ++nxt;
	return mrw[node] = max(mrw[node], add(trie[node][s[pos] - 'a'], pos + 1));
}

// bool to treat the -1 case
bool qry(int node = 0, int pos = 0){
	if(pos == s.size()){
		// lexicographical order if many equally repeated words
		if(this_node[node] == mrw[node]){
			cout << fim[node] << " " << mrw[node] << '\n';
			return true;
		}
		for(int i = 0; i < 30; i++){
			int nxt_node = trie[node][i];
			if(nxt_node && mrw[node] == mrw[nxt_node])
				return qry(nxt_node, pos);
		}
	}
	else{
		if(!trie[node][s[pos] - 'a'])
			return false;
		return qry(trie[node][s[pos] - 'a'], pos + 1);
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
	while(t--){
		cin >> s;
		if(!qry())
			cout << "-1\n";
	}
	
	return 0;
}
