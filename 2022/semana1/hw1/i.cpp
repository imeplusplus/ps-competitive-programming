#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = n; i > n-k; i--) cout << i << " ";
	for (int i = 1; i <= n-k; i++) cout << i << " ";
	cout << '\n';
 
	return 0;
}