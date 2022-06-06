// W = 1, B = -1
// DFS to get the sum over each subtree
// Answer = # (sum == 0)

#include<bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;

int ans, v[N];
vector<int> adj[N];

int dfs(int pos){
	int sum = v[pos];
	for(int i : adj[pos])
		sum += dfs(i);
	ans += (sum == 0);
	return sum;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ans = 0;
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		for(int i = 2; i <= n; i++){
			int u;
			scanf("%d", &u);
			adj[u].push_back(i);
		}
		for(int i = 1; i <= n; i++){
			char c;
			scanf(" %c", &c);
			if(c == 'W')
				v[i] = 1;
			else
				v[i] = -1;
		}
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
