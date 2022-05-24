/*
    Key idea:
        This problem has no crazy idea, it's just a minimum segtree with update and query in range.
        The difficulties of this problem are two:
            1) Read the input (very boring problem, sorry)
            2) Segment tree is circular
        
        1)  To treat the first problem, I read the line and parsed the string until a " " is found
            Read function parse for more details.
        2) The circular part can be solved with a if else statement

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

int n, m;
ll st[4*N], v[N], lazy[4*N], op[3];
char str[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

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
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (int p, int l, int r, int i, int j, ll k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = min(st[2*p], st[2*p+1]);
}

int parse(){
    string cur;
    int sz = strlen(str);
    int id = 0;
    //parse string until a " " is found and store the number
    for(int i = 0; i < sz; i++){
        if(str[i] == ' '){
            op[id] = stoi(cur);
            id++;
            cur.clear();
        }
        else{
            cur += str[i];
        }
    }
    //store last number
    op[id] = stoi(cur);
    //stoi can take care of negative numbers
    return id;
}

int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++) scanf(" %lld", &v[i]);
    build(1, 0, n - 1);

    scanf( "%d", &m);
    for(int i = 0; i < m; i++){
        //dont forget to put the space before % to clear buffer
        scanf(" %[^\n]s", str);
        int cnt = parse();
        if(cnt == 2){
            //if normal order, just do normal update  
            if(op[0] <= op[1])
                update(1, 0, n - 1, op[0], op[1], op[2]);
            //otherwise, update: 0 ~ op[1] and op[0] ~ n - 1
            else{
                update(1, 0, n - 1, 0, op[1], op[2]);
                update(1, 0, n - 1, op[0], n - 1, op[2]);
            }
        }
        else{
            ll ans = 0;
            if(op[0] <= op[1])
                ans = query(1, 0, n - 1, op[0], op[1]);
            else{
                ans = query(1, 0, n - 1, 0, op[1]);
                ans = min(ans, query(1, 0, n - 1, op[0], n - 1));
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}