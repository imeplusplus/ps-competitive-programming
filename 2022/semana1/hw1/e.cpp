#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	set<int> s;
	cin >> t;
	char query, last_query = NULL;
	int a, last_a;
	while(t--){
		cin >> query >> a;
		if(query == '+'){
			if(last_query == '+') s.insert(a);
			else s.insert((a+last_a)%N);
		} 
		else {
			auto it = s.lower_bound(a);
			if(it != s.end()) cout << *it << '\n';
			else cout << "-1\n";
			last_a = *it;
		}
		last_query = query;
	}
	return 0;
}

// 1 3