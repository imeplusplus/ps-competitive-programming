// Solution
// Kadane

#include<bits/stdc++.h>
using namespace std;

int n, v, cur, ans;

int main(){
	scanf("%d", &n);
	while(n){
		ans = cur = 0;
		while(n--){
			scanf("%d", &v);
			cur += v;
			ans = max(ans, cur);
			if(cur < 0)
				cur = 0;
		}
		if(ans)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
		scanf("%d", &n);
	}
	return 0;
}
