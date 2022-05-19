// DSU, join the ones that are on the same tree

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, sz[N], fat[N], ans, p;

int find(int a){
	if(fat[a] == a)
		return a;
	return fat[a] = find(fat[a]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	fat[b] = a;
	
	// Every successful union decreases the number of different trees 
	ans--;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		sz[i] = 1;
		fat[i] = i;
	}
	
	// Start with n different trees
	ans = n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p);
		join(i, p);
	}
	printf("%d\n", ans);
	return 0;
}
