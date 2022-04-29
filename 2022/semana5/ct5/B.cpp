// Construct the graph
// For each conected component, roll a dfs
// Try to choose "male" (1) and "female" (2) alternately

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int t, n, m, u, v, gender[N];
vector<int> adj[N];

bool dfs(int p, int gen){
	// if visited, return true if suspicious and false otherwise
	if(gender[p] != 0)
		return gender[p] != gen;
		
	gender[p] = gen;
	for(int i : adj[p])
		// if 1, next to be 2. if 2, next to be 1
		if(dfs(i, gen % 2 + 1))
			return true;
	
	// no suspicious bugs found
	return false;
}

int main(){
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++){
		scanf("%d %d", &n, &m);
		
		// clear the graph
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			gender[i] = 0;
		}
		
		// build new graph
		while(m--){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		// search for suspicious bugs
		bool suspicious = false;
		for(int i = 1; i <= n; i++)
			// not yet visited
			if(gender[i] == 0)
				suspicious |= dfs(i, 1);
		
		printf("Scenario #%d:\n", tt);
		if(suspicious)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
	}
}
