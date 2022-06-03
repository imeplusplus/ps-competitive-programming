//@xixo
#include <bits/stdc++.h>
using namespace std;

int n;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool check(vector<int> &v, int pos, int val){
	if(!binary_search(p, p+11, v[pos-1]+val)) return false;
	for(int i = 0; i<pos; i++) if(val == v[i]) return false;
	if(pos == v.size()-1 and !binary_search(p, p+11, 1+val)) return false;
	return true;
}

void bt(vector<int> &v, int pos){
	if(pos == v.size()){
		for(int i = 0; i<v.size()-1; i++) cout << v[i] << " ";
		cout << v.back() << '\n';
		return;
	}
	for(int i = 2; i<=v.size(); i++) if(check(v, pos, i)){
		v[pos] = i;
		bt(v, pos+1);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 2; i<=16; i+=2){
	}
	int cnt = 0;
	while(cin >> n){
		if(cnt) cout << '\n';
		cnt++;
		cout << "Case " << cnt << ":\n";
		vector<int> loop(n);
		loop[0]=1;
		bt(loop, 1);
	}
	return 0;
}