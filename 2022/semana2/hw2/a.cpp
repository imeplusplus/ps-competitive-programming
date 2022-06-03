//@xixo
#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, x, y;
	cin >> x >> y >> a >> b;
	vector<pair<int, int>> ans;
	int curr_a = max(a, b+1);
	while(curr_a<=x){
		for(int i = b; i<curr_a and i<=y; i++) ans.push_back({curr_a, i});
		curr_a++;
	}
	cout << ans.size() << '\n';
	for(pair<int, int> i: ans) cout << i.first << " " << i.second << '\n';
	return 0;
}