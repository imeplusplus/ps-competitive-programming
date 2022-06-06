// KMP

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int lps[N];

void prekmp(string &p){
	for (int i = 1, j = 0; i < p.size(); i++) {
		while (j and p[j] != p[i]) j = lps[j-1];
		if (p[j] == p[i]) j++;
		lps[i] = j;
	}
}

bool kmp(string &s, string &p) {
	for (int i = 0, j = 0; i < s.size(); i++) {
		while (j and p[j] != s[i]) j = lps[j-1];
		if (p[j] == s[i]) j++;
		if (j == p.size()) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, ant, at;
		string s, p;
		cin >> n;
		cin >> ant;
		n--;
		while(n--){
			cin >> at;
			if(at > ant)
				s += 'G';
			else if(at < ant)
				s += 'L';
			else
				s += 'E';
			ant = at;
		}
		cin >> p;
		prekmp(p);
		if(kmp(s, p))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
