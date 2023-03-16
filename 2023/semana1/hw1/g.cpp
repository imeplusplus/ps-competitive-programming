#include <bits/stdc++.h>
using namespace std;


const int N = 1e5+5;
int v[N];

int bin_srch(int l, int r, int val){
		int mid = (l+r)/2;
	while(l<r){
		if(v[mid] < val) l = mid + 1;
		else r = mid;
		mid = (l+r)/2;
	}
	return mid;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i<n; i++) cin >> v[i];
	while(q--){
		int a;
		cin >> a;
		int aux = bin_srch(0, n-1, a);
		if(v[aux] == a) cout << aux << '\n';
		else cout << "-1\n"; 
	}
	return 0;
}