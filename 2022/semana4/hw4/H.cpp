// Solution
// First let's consider we have to achieve the exact amount of money, without change
// This would be a knapsack of the minimum value
// Consider the repetitions of coins as different objects
// with the same weigth, being the value of the coin,
// and all objects with value = 1

// But since it has the possibility of change, after the knapsack we
// still have to consider the change costs.
// This cost would be the minimum number of coins to give the change needed,
// considering we have as many of each coin we need.
// This could also be done using a knapsack on the value of the change
// by considering 100 repetitions of each coin,
// but we actually CAN use a greedy aproach in this case.
// The reason for that is that there's always a way to change smaller value coins for
// a combination using greater value coins and ending up with less coins

// 2 coins of 5c -> 1 coin of 10c
// 2 coins of 10c -> 1 coin of 20c
// 3 coins of 20c -> 1 coin of 50c + 1 coin of 10c
// 2 coins of 50c -> 1 coin of 1$
// 2 coins of 1$ -> 1 coin of 2$

// a.k.a., we do not use more than 1 coin of 5c, 10c, 50c or 1$
// and not more than 2 coins of 20c for any amount of money.

// Atention for the presentation of the output

#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

int ks[N][N], w[N], t, aux[6] = {5, 10, 20, 50, 100, 200}, x, h, W, dol, cent, ans;

int changeCost(int change){
	int r = 0;
	for(int i = 5; i >= 0; i--)
		while(change >= aux[i]){
			r++;
			change -= aux[i];
		}
	return r;
}

int main(){
	// Use h to see if we should stop the test cases
	for(int i = 0; i < 6; i++){
		scanf("%d", &x);
		h += x;
		// Make x identical objects with weight aux[i]
		while(x--){
			t++;
			w[t] = aux[i];
		}
	}
	while(h){
		scanf("%d.%d", &dol, &cent);
		W = 100 * dol + cent;
		
		// For knapsack of minimum we have to set ks[0][j] = INF, or N in this case
		// Let just ks[0][0] = 0
		for(int j = 1; j < N; j++)
			ks[0][j] = N;
		for(int i = 1; i <= t; i++)
			for(int j = 0; j < N; j++){
				if(j >= w[i])
					ks[i][j] = min(ks[i - 1][j], ks[i - 1][j - w[i]] + 1);
				else
					ks[i][j] = ks[i - 1][j];
			}
			
		// Consider the cange costs
		ans = N;
		for(int j = W; j < N; j++)
			ans = min(ans, ks[t][j] + changeCost(j - W));
		printf("%3d\n", ans);
		
		// Check if we should continue another test case
		h = t = 0;
		for(int i = 0; i < 6; i++){
			scanf("%d", &x);
			h += x;
			while(x--){
				t++;
				w[t] = aux[i];
			}
		}
	}
	return 0;
}
