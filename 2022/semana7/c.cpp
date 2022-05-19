/*
    key idea:
        read all inputs and save
        do the algorithm to compress the coordinates
        apply segtree for maximum in range, with lazy update
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

//variables
int n, q;
map<int, int> id;
pii ini[N], qry[N];

//segtree
ll st[4*N], lazy[N];

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += lazy[p];
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p] = 0;
    }
}

ll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = max(st[2*p], st[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v;
    //le todas os valores iniciais, guarda no vetor dos iniciais e no vetor de compressao
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        ini[i] = {l, r};
        v.push_back(l);
        v.push_back(r);
    }

    //le todas as querys, guarda num vetor de querys e no vetor de compressao
    cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        qry[i] = {l, r};
        v.push_back(l);
        v.push_back(r);
    }

    //ordena
    sort(v.begin(), v.end());
    //deixa so os unicos
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    for(int i = 0; i < v.size(); i++){
        //mapeia com um novo valor
        id[v[i]] = i;
        //id reverso para recuperar depois
        //revid[i] = v[i];
    }

    //pega valor maximo, para usar na segtree
    int MAX_RANGE = v.size() - 1;

    //valores estao devidamente mapeados e comprimidos, podemos agora inicializar e realizar as querys, usando o novo id
    //inicializa
    for(int i = 1; i <= n; i++){
        update(1, 0, MAX_RANGE, id[ini[i].st], id[ini[i].nd], 1);
    }
    //realiza query
    for(int i = 1; i <= q; i++){
        cout << query(1, 0, MAX_RANGE, id[qry[i].st], id[qry[i].nd]) << "\n";
    }
    return 0;
}