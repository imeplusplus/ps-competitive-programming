// Dijkstra for each query
// Atention for the corner case of a graph that's not connected
// If there is no path to another city, it should not be considered

// O(Q * max(N, M) * log(max(N, M)))
// As stated, Q * max(N, M) * log(max(N, M)) <= 2e8
// Since it's a little high, let's do minor optimizations in our dijkstra implementation

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 5e5 + 5, INF = 1e9;

int n, m, q, d[N];
bool vis[N];
vector<pii> adj[N];

void dijkstra(int start){
	priority_queue<pii> pq;
	
	// Set d[start] = 0
	pq.push({d[start] = 0, start});
	while(!pq.empty()){
		pii t = pq.top();
		pq.pop();
		
		// visited array since the priority queue may have repeated values
		if(vis[t.nd])
			continue;
		vis[t.nd] = true;
		
		for(pii i : adj[t.nd])
			// t.st = -dist to use normal priority_queue
			if(i.st - t.st < d[i.nd]){
				// Set d[i.nd] to avoid pushing i.nd into the priority queue more than necessary
				// It may still have repeated nodes in the priority queue, it just avoids some of them
				d[i.nd] = i.st - t.st;
				pq.push({-d[i.nd], i.nd});
			}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	
	while(m--){
		int u, v, dist;
		scanf("%d %d %d", &u, &v, &dist);
		adj[u].push_back({dist, v});
		adj[v].push_back({dist, u});
	}
	
	while(q--){
		int start;
		scanf("%d", &start);
		
		// Reset for each query
		for(int i = 0; i < n; i++){
			d[i] = INF;
			vis[i] = false;
		}
		dijkstra(start);
	
		int maxDist = 0, qtd = 0;
		for(int i = 0; i < n; i++){
			
			// Found a larger distance AND the nodes are in the same connected graph
			if(d[i] > maxDist && d[i] < INF){
				maxDist = d[i];
				qtd = 0;
			}
			if(d[i] == maxDist)
				qtd++;
		}
		
		printf("%d %d\n", maxDist, qtd);
	}	
	return 0;
}
