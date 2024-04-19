// Let's consider the root to be 1, depth[1] = 1 and sz[i] = number of nodes in the subtree
// rooted in node i.

// First notice that it's never a good choice to pick a node to be an industry city
// if there is some of it's children that are tourism cities.

// Thus, each city i that we choose to be an industry city will add to the happiness
// an amount of depth[i] - sz[i] 

// (it will pass through depth[i] - 1 tourism cities to get to the capital and will 
// decrease 1 tourims city, which is itself, from each of the sz[i] - 1 paths from 
// industry cities of its subtree to the capital).

// So we choose in a greedy manner the k best cities.

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, u, v, sz[N], depth[N];
bool vis[N];
vector<int> adj[N];
long long ans;
priority_queue<int> pq;

void dfs(int p){
	sz[p] = 1;
	vis[p] = true;
	for(int i : adj[p])
		if(!vis[i]){
			depth[i] = depth[p] + 1;
			dfs(i);
			sz[p] += sz[i];
		}
		
	// Put the amounts on a priority queue
	pq.push(depth[p] - sz[p]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
	for(int i = 1; i < n; i++){
        cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[1] = 1;
	dfs(1);
	
	// Get the k best nodes
	while(k--){
		// Atention to overflow
		ans += pq.top();
		pq.pop();
	}
    cout << ans << "\n";
    return 0;
}
