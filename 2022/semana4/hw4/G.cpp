// Solution
// LIS

#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int lis[N], v[N], n, ans;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++)
			if(v[j] < v[i])
				lis[i] = max(lis[i], lis[j] + 1);
		ans = max(ans, lis[i]);
	}
	printf("%d\n", ans);
	return 0;
}
