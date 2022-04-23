// Solution
// Need x quasibinaries to match a digit = x

#include<bits/stdc++.h>
using namespace std;

int n, digit[7], maxDigit;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 7; i++){
		digit[i] = n % 10;
		n /= 10;
		maxDigit = max(maxDigit, digit[i]);
	}
	printf("%d\n", maxDigit);
	for(int i = 0; i < maxDigit; i++){
		int quasiBin = 0;
		for(int j = 6; j >= 0; j--)
			quasiBin = 10 * quasiBin + (digit[j] > i);
		printf("%d ", quasiBin);
	}
	return 0;
}
