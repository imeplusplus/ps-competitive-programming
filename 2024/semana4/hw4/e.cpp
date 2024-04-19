// MST

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 1e5 + 5;

int n, m;
vector<pli> adj[N];
bool vis[N];

ll mst(){
	ll ans = 0;
	priority_queue<pli> pq;
	
	pq.push({0, 1});
	while(!pq.empty()){
		pli t = pq.top();
		pq.pop();
		
		if(vis[t.nd])
			continue;
		vis[t.nd] = true;
		
		// t.st = -dist to use normal priority_queue
		ans -= t.st;
		
		for(pli i : adj[t.nd])
			pq.push(i);
	}
	
	return ans;
}

int main(){
	scanf("%d %d", &n, &m);
	
	while(m--){
		int u, v, dist;
		scanf("%d %d %d", &u, &v, &dist);
		
		// Store -dist to use normal priority_queue
		adj[u].push_back({-dist, v});
		adj[v].push_back({-dist, u});
	}
	
	printf("%lld\n", mst());
	
	return 0;
}
