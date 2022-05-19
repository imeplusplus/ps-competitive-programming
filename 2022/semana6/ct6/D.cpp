// MST
// Actually Minimum Spanning Forest with given roots

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 1e5 + 5;

int t, n, m;
vector<pli> adj[N];
vector<int> milkmen;
bool vis[N];

ll mst(){
	ll ans = 0;
	priority_queue<pli> pq;
	
	for(int i : milkmen)
		pq.push({0, i});
	while(!pq.empty()){
		pli t = pq.top();
		pq.pop();
		
		if(vis[t.nd])
			continue;
		vis[t.nd] = true;
		
		// One less milkless person for each successful iteration
		n--;
		
		// t.st = -dist to use normal priority_queue
		ans -= t.st;
		
		for(pli i : adj[t.nd])
			pq.push(i);
	}
	
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		
		// Reset for each test case
		milkmen.clear();
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			vis[i] = false;
		}
		
		// Get the milkmen
		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			if(x)
				milkmen.push_back(i);
		}
		
		while(m--){
			int u, v, dist;
			scanf("%d %d %d", &u, &v, &dist);
			
			// Store -dist to use normal priority_queue
			adj[u].push_back({-dist, v});
			adj[v].push_back({-dist, u});
		}
		
		ll ans = mst();
		
		// No milkless person
		if(n == 0)
			printf("%lld\n", ans);
		else
			printf("impossible\n");
	}
	return 0;
}
