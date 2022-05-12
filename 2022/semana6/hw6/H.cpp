// DSU
// Maintain the friends in the same group
// Keep 1 adversary of the friend's group in the root of the group
// When joining friends, join their enemies as well

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

// If the group has no enemies yet, adv[root] = -1
int n, sz[N], fat[N], adv[N];

// All functions may be called with a -1 because of the adv[] variable
// So watch out!
int find(int a){
	if(a == -1)
		return -1;
	if(fat[a] == a)
		return a;
	return fat[a] = find(fat[a]);
}

// enemy(a) gets the adversary stored on the root of a's friend group
int enemy(int a){
	if(a == -1)
		return -1;
	return find(adv[find(a)]);
}

void join(int a, int b){
	if(a == -1 || b == -1)
		return;
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	fat[b] = a;
	
	// If group a has no adversary, make adv[b] it's adversary
	// adv[b] may be -1, but then it changes nothing
	if(adv[a] == -1)
		adv[a] = adv[b];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		sz[i] = 1;
		adv[i] = -1;
		fat[i] = i;
	}
	int c, u, v;
	scanf("%d %d %d", &c, &u, &v);
	while(c + u + v){
		
		// Join friends if they are not already enemies
		if(c == 1){
			if(find(enemy(u)) == find(v))
				printf("-1\n");
			else{
				// Join the enemies of the new friends
				join(enemy(u), enemy(v));
				join(u, v);
			}
		}
		
		// Make enemies if they are not already friends
		else if(c == 2){
			if(find(u) == find(v))
				printf("-1\n");
			else{
				// After joining enemy(u) and v, enemy(v) can change to u
				// So to be able to join enemy(v) and u later, we need h
				int h = enemy(v);
				join(enemy(u), v);
				join(h, u);
				
				// Everyone starts with no enemies, this is to make sure we keep
				// one adversary on the root of each friend group
				adv[find(u)] = v;
				adv[find(v)] = u;
			}
		}
		
		// Checks for friendship
		else if(c == 3){
			if(find(u) == find(v))
				printf("1\n");
			else
				printf("0\n");
		}
		
		// Checks for rivalry
		else{
			if(enemy(u) == find(v))
				printf("1\n");
			else
				printf("0\n");
		}
		scanf("%d %d %d", &c, &u, &v);
	}
	return 0;
}
