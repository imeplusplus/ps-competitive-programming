#include <bits/stdc++.h>
using namespace std;

//a ideia é no merge sort, contar cada vez que tiver que botar um
//elemento do vetor da direita na frente de algum da esquerda e ai incrementa o cnt
//da quantidade restante de elementos da esquerda, é a linha comentada com "inversion" do lado
 

long long cnt; //ATENÇÃO AO LONG LONG, com int da overflow

vector<int> merge(vector<int> v){
    int sz = (int)v.size();
    if(sz == 1) return v;
    vector<int> l, r;
    for(int i = 0; i < (sz)/2; i++) l.push_back(v[i]);
    for(int i = (sz)/2; i < sz; i++) r.push_back(v[i]);
    l = merge(l), r = merge(r);
    int pl = 0, pr = 0;
    vector<int> ans;
    while(pl < l.size() or pr < r.size()){
        if(pl >= l.size()) ans.push_back(r[pr++]);
        else if(pr >= r.size()) ans.push_back(l[pl++]);
        else if(r[pr] >= l[pl]) ans.push_back(l[pl++]);
        else ans.push_back(r[pr++]), cnt += l.size() - pl; //inversion
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i<n; i++) cin >> v[i];
		cnt = 0;
		merge(v);
		cout << cnt << '\n';
	}
	return 0;
}