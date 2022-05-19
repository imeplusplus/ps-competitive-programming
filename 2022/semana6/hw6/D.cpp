// Reverse each edge and run dijkstra starting from the exit

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 1e5 + 5, INF = 1e9;

int tests, d[N];
vector<pii> adj[N];

void dijkstra(int st){
	priority_queue<pii> pq;
	pq.push({0, st});
	while(!pq.empty()){
		pii t = pq.top();
		pq.pop();
		
		// t.st = -dist to use normal priority_queue
		if(d[t.nd] <= -t.st)
			continue;
		d[t.nd] = -t.st;
		
		for(pii i : adj[t.nd])
			pq.push({t.st - i.st, i.nd});
	}
}

int main(){
	scanf("%d", &tests);
	
	// Only for presentation purposes
	bool first = true;
	while(tests--){
		if(!first)
			printf("\n");
		first = false;
		
		int n, e, t, m;
		scanf("%d %d %d %d", &n, &e, &t, &m);
		
		// Reset adjacency vector and distance array for each test
		for(int i = 1; i <= n; i++){
			d[i] = INF;
			adj[i].clear();
		}
		
		while(m--){
			int u, v, dist;
			scanf("%d %d %d", &u, &v, &dist);

			// Add reversed edge
			adj[v].push_back({dist, u});
		}
		
		dijkstra(e);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(d[i] <= t)
				ans++;
				
		printf("%d\n", ans);
	}
		
	return 0;
}
