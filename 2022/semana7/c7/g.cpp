/*
    Key idea: Segment Tree for range update and query
        do sieve first to know if a number is prime or not
        at each update, update with !p[v] (prime or not)
        do range query to retrieve the answer
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
const int N = 1e6 + 5;

int p[N], st[4*N], v[N], lazy[4*N];

void sieve(){
    for (ll i = 2; i < N; ++i){
        if (!p[i]) {
            for (ll j = i*i; j < N; j += i) 
                p[j] = 1;
        }
    }
}

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

/*
    Lets define:    lazy = -1 (no updates needed)
                    lazy = 1 or lazy = 0 (update interval with prime or not prime)
*/


void push (int p, int l, int r) {
    if (lazy[p] != -1) {
        st[p] = (r-l+1)*lazy[p];
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p] = -1;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cout << "Case " << k << ":\n";
        int n, q;
        memset(lazy, -1, sizeof(lazy));

        //if you build every test case, this is not needed
        memset(st, 0, sizeof(st));
        memset(v, 0, sizeof(v));

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;

            //value of v[i] depends whether x is prime or not
            //p[x] = 0 means x is prime, so we invert p[x]
            v[i] = !p[x];
        }

        //build segtree
        build(1, 1, n);

        for(int i = 0; i < q; i++){
            int op, x, y, v;
            cin >> op >> x >> y;
            if(op == 0){
                cin >> v;

                //update: p[v] = 0 means v is prime, so we invert p[v]
                update(1, 1, n, x, y, !p[v]);
            }
            else{
                cout << query(1, 1, n, x, y) << "\n";
            }
        }
    }
    return 0;
}