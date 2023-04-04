// Dijkstra

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 1e5 + 5;

// For many tests, use vis[N] = x instead of vis[N] = true
int x, vis[N];
vector<pii> adj[N];

int dijkstra(int st, int fi){
	priority_queue<pii> pq;
	pq.push({0, st});
	while(!pq.empty()){
		pii t = pq.top();
		pq.pop();
		
		// t.st = -dist to use normal priority_queue
		if(t.nd == fi)
			return -t.st;
		if(vis[t.nd] == x)
			continue;
			
		vis[t.nd] = x;
		for(pii i : adj[t.nd])
			pq.push({t.st - i.nd, i.st});
	}
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, st, fi;
		scanf("%d %d %d %d", &n, &m, &st, &fi);
		x++;
		
		// Reset adjacency vector for each test
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		while(m--){
			int u, v, dist;
			scanf("%d %d %d", &u, &v, &dist);
			adj[u].push_back({v, dist});
			adj[v].push_back({u, dist});
		}
		
		int ans = dijkstra(st, fi);
		if(ans >= 0)
			printf("%d\n", ans);
		else
			printf("NONE\n");
	}
	return 0;
}