// BFS using the moves allowed

#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4;

// For many tests, use vis[N] = x instead of vis[N] = true
int t, x, vis[N];

int bfs(int st, int fi){
	queue<pii> q;
	if(vis[st] < x){
		vis[st] = x;
		q.push({0, st});
	}
	while(!q.empty()){
		pii f = q.front();
		q.pop();
		if(f.nd == fi)
			return f.st;
			
		// Try all the digit changes
		for(int i = 1; i < N; i *= 10)
			for(int j = 0; j < 10; j++){
				int nxt = f.nd + (j - f.nd / i % 10) * i;
				
				// Check if nxt valid and not yet visited in this test
				if(vis[nxt] < x){
					vis[nxt] = x;
					q.push({f.st + 1, nxt});
				}
			}
	}
	return -1;
}

int main(){
	// vis[i] = N (invalid positions) for i coprime
	for(ll i = 2; i < N; i++){
		if(vis[i])
			continue;
		for(ll j = i * i; j < N; j += i)
			vis[j] = N;
	}
	// vis[i] = N (invalid positions) for i with lass than 4 digits
	for(int i = 0; i < N / 10; i++)
		vis[i] = N;
		
	scanf("%d", &t);
	while(t--){
		x++;
		int st, fi;
		scanf("%d %d", &st, &fi);
		int ans = bfs(st, fi);
		if(ans >= 0)
			printf("%d\n", ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
