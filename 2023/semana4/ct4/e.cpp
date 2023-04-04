// Increase the number of cookies wanted until it's not feasible to make them anymore
// O(check solution * answer)
// Notice that we have at most a_max + K grams of each ingredient,
// Thus the number of cookies can never be more than a_max + K and we get O(N * (a_max + K))

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, mp, a[N], b[N];

bool val(int cookies){
	int mp_needed = 0;
	for(int i = 0; i < n; i++)
		mp_needed += max(0, a[i] * cookies - b[i]);
	return mp_needed <= mp;
}

int main(){
	scanf("%d %d", &n, &mp);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int ans = 0;
	while(val(ans))
		ans++;
	printf("%d\n", ans - 1);
	return 0;
}