/*
    Key idea:
        Use a segment tree of MAXIMUM to calculate the minimum required in that range
        the answer should be: 
            abs(number_of_balloons_now - query)
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
const int N = 1e5+5;

int t, n, m, q;

int st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = max(st[2*p], st[2*p+1]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int y = 0; y < t; y++){
        cout << "Testcase " << y << ":\n";
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> v[i];
        build(1, 0, n - 1);
        cin >> q;
        for(int x = 0; x < q; x++){
            char op;
            int i, j, k;
            cin >> op;
            //increase or decrease current numbers of balloons 
            if(op == 'A'){
                cin >> k;
                m += k;
            }
            //update number of balloons in position j
            if(op == 'B'){
                cin >> j >> k;
                update(1, 0, n - 1, j, k);
            }
            //difference between minimum and necessary
            if(op == 'C'){
                cin >> i >> j;
                cout << abs(m - query(1, 0, n - 1, i, j)) << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}