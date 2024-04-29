// TopoSort with priority queue

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, q[N];
vector<int> adj[N], ans;
priority_queue<int> pq;

int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		int x, y;
		scanf("%d %d", &x, &y);
		q[y]++;
		adj[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
		if(!q[i])
			// -i to use normal priority queue
			pq.push(-i);
	while(!pq.empty()){
		int t = -pq.top();
		ans.push_back(t);
		pq.pop();
		for(int i : adj[t]){
			q[i]--;
			if(!q[i])
				pq.push(-i);
		}
	}
	if(ans.size() == n)
		for(int i : ans)
			printf("%d ", i);
	else
		printf("Sandro fails.\n");
	return 0;
}
