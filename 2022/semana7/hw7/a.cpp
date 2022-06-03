/*
	Basic fenwick tree problem, with update, query and rangesum.
	Application of the technique.

*/

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll bit[N];
int n, q;

void update(ll x, int pos) {
	while(pos <= n) {
		bit[pos] += x;
		pos += pos&(-pos);
	}
}

ll query(int pos) {
	ll r = 0;
	while(pos) {
		r+= bit[pos];
		pos -= pos&(-pos);
	}
	return r;
}

ll rangesum(int l, int r) {
	return query(r) - (l? query(l-1) : 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		update(x, i);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		char op;
		int l, r;
		cin >> op >> l >> r;
		if(op == 'q') cout << rangesum(l, r) << "\n";
		else update(r, l);
	}
    return 0;
}