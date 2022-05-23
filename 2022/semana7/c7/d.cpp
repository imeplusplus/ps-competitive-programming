/*
    Key idea:
        Unite and keep updated min and max sizes
            Use a map to keep updated

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

int n, q;

map<int, int> m;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    m[sz[a]]--, m[sz[b]]--;
    
    //remove old map
    if(!m[sz[a]]) m.erase(sz[a]);
    if(!m[sz[b]]) m.erase(sz[b]);

    sz[a] += sz[b];
    par[b] = a;

    //insert in new map
    m[sz[a]]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        par[i] = i, sz[i] = 1;
        m[sz[i]]++;
    }

    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << m.rbegin()->st - m.begin()->st << "\n";
    }
    return 0;
}