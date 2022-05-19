/*
    The key idea is to create a segtree with pairs.
    pairs represent {value of the maximum element in that range, position of the maximum element}
    so we will search for i first and find max, remove it from segtree ,
    then we remove from segtree (because i != j) and search for max a[j]
    
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

pair<int, int> st[4*N];
int a[N], n, q;

void build (int p, int l, int r) {
    if (l == r) {st[p] = {a[l], l}; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}


pair<int, int> query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {-INF, -INF};
    if (i <= l and r <= j) return st[p];
    pair<int, int> x = query(2*p, l, (l+r)/2, i, j);
    pair<int, int> y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = {v, x}; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = max(st[2*p], st[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    for(int i = 0; i < q; i++){
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'Q'){
            //max1 is between x and n
            pair<int, int> max1 = query(1, 1, n, x, y);
            //remove temporarily from segtree because i != j;
            update(1, 1, n, max1.nd, 0);


            //max1 is between y and n
            pair<int, int> max2 = query(1, 1, n, x, y);
            cout << max1.st + max2.st << "\n";

            //insert the number again on seg tree
            update(1, 1, n, max1.nd, max1.st);
        }
        else{
            //update pos x with value y
            update(1, 1, n, x, y);
        }
    }
    return 0;
}