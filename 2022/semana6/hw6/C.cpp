// Recover dijkstra path

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 1e5 + 5;
const ll INF = 1e12;

int n, m;
ll d[N];
vector<pli> adj[N];

void dijkstra(){
	priority_queue<pli> pq;
	pq.push({0, 1});
	while(!pq.empty()){
		pli t = pq.top();
		pq.pop();
		
		// t.st = -dist to use normal priority_queue
		if(d[t.nd] <= -t.st)
			continue;
		d[t.nd] = -t.st;
		
		for(pli i : adj[t.nd])
			pq.push({t.st - i.st, i.nd});
	}
}

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++)
		d[i] = INF;
	
	while(m--){
		int u, v, dist;
		scanf("%d %d %d", &u, &v, &dist);
		adj[u].push_back({dist, v});
		adj[v].push_back({dist, u});
	}
	
	dijkstra();
	
	if(d[n] < INF){
		vector<int> v = {n};
		int nxt = n;
		while(nxt != 1){
			for(pli i : adj[nxt])
				if(d[nxt] == d[i.nd] + i.st){
					nxt = i.nd;
					break;
				}
			v.push_back(nxt);
		}
		reverse(v.begin(), v.end());
		
		for(int i : v)
			printf("%d ", i);
	}
	else
		printf("-1\n");
		
	return 0;
}
