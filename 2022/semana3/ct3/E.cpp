// Binary search on the solution
// Check if it's possible to leave the cows on a distance of 'd' from each other
// If it's possible, decrease 'd', otherwise increase it
// Check it by putting the cows as close as possible as long as it's >= 'd'
// Remember to sort the array first

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int t, n, c, x[N];

// O(n)
bool possible(int d){
	// Already allocate the first cow at position x[0]
	int cowsAllocated = 1;
	int lastCowPosition = x[0];
	
	for(int i = 1; i < n; i++)
		// Check the distance just for the last cow, which will be the closest one
		if(x[i] - lastCowPosition >= d){
			lastCowPosition = x[i];
			cowsAllocated++;
		}
		
	// If it fits >= c cows with a distance of 'd' away from each other, return true
	return cowsAllocated >= c;
}

// O(n*log(hi))
int binSearch(){
	int lo = 0, hi = 1e9;
	while(lo < hi){
		int mid = (lo + hi + 1) / 2;
		if(possible(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

// O(t*n*log(hi))
int main(){
    scanf("%d", &t);
    while(t--){
    	scanf("%d %d", &n, &c);
    	for(int i = 0; i < n; i++)
    		scanf("%d", &x[i]);
    	
    	// first sort it
    	sort(x, x + n);
    	
    	printf("%d\n", binSearch());
	}
    return 0;
}
