// DSU

#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int t, sz[N], fat[N], n;

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
	
	// Every successful union decreases the number of maximal subgraphs 
	n--;
}

int main(){
	scanf("%d", &t);
	char s[3];
	scanf(" %s", s);
	
	// Presentation purposes
	bool first = true;
	while(t--){
		if(!first)
			printf("\n");
		first = false;
		
		// Number of maximal connected subgraphs
		n = s[0] - 'A' + 1;
		// Reset sz and fat for every test case
		for(int i = 0; i < n; i++){
			sz[i] = 1;
			fat[i] = i;
		}
		
		while(scanf(" %s", s) != EOF && strlen(s) == 2)
			join(s[0] - 'A', s[1] - 'A');
		printf("%d\n", n);
	}
	return 0;
}
