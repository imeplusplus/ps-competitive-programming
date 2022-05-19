// For each path from a leaf to the root we'll need to put each node in a different group
// So the answer is the length of the largest path from a leaf to the root
// This can be calculated by a dfs
// Notice that the graph will be a forest, therefore there may be many different roots

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int n, p[N], ans;
vector<int> adj[N];

int dfs(int u){
	int r = 0;
	
	// get the largest branch
	for(int i : adj[u])
		r = max(r, dfs(i));
		
	// add the current node
	return r + 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		if(p[i] > 0)
			adj[p[i]].push_back(i);
	}
	
	// Get the largest branch starting from each root
	for(int i = 1; i <= n; i++)
		if(p[i] == -1)
			ans = max(ans, dfs(i));
	
	printf("%d\n", ans);
}
