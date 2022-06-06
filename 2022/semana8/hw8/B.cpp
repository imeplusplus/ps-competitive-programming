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

int kmp(){
	int ans = 0;
	int j = 0;
	for(int i = 0; i < s.size(); i++){
		while(j && p[j] != s[i])
			j = lps[j - 1];
		if(p[j] == s[i])
			j++;
			
		/* only change
		if(j == p.size()){
			cnt++;
			j = lps[j - 1];
		}
		*/
		ans = max(ans, j);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> p;
		prekmp();
		s = p;
		reverse(s.begin(), s.end());
		// kmp on p and reverse(p)
		// gives the longest substring that is prefix of p and is a substring of reverse(p)
		p.resize(kmp());
		
		// The answer is actually the reverse, which is a substring somewhere in the string
		reverse(p.begin(), p.end());
		cout << p << '\n';
	}
	return 0;
}
