#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

bool cmp(pair<int, int> u, pair<int, int> v){
	return ((u.first<v.first) or (u.first==v.first and u.second>v.second));
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		pair<int, int> p[N];
		for(int i = 0; i<n; i++) cin >> p[i].first >> p[i].second;
		sort(p, p+n, cmp);
		for(int i = 0; i<n; i++) cout << p[i].first << " " << p[i].second << '\n';
	}
	return 0;
}