#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

string s, p;
int lps[N];

// if you don't know kmp, ask for help
void prekmp(){
	int j = 0;
	for(int i = 1; i < p.size(); i++){
		while(j && p[j] != p[i])
			j = lps[j - 1];
		if(p[j] == p[i])
			j++;
		lps[i] = j;
	}
}

vector<int> kmp(){
	vector<int> ans;
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		while(j && p[j] != s[i])
			j = lps[j - 1];
		if(p[j] == s[i])
			j++;
		if(j == p.size()){
			// cnt++
			// only change
			ans.push_back(i + 2 - p.size());
			j = lps[j - 1];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> s >> p;
		prekmp();
		vector<int> ans = kmp();
		if(ans.empty())
			cout << "Not Found\n\n";
		else{
			cout << ans.size() << '\n';
			for(int i : ans)
				cout << i << " ";
			cout << "\n\n";
		}
	}
	return 0;
}
