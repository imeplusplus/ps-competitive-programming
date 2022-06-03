/*
    Key idea:
        Count how much wires cross wire i.
        If the wire starts at position i and connects to position j,
        the wires that will cross it are all the wires that start at position x < i and end at position y >= j
        You can simulate and see that this is a optimal solution.

        We can iterate through the wires and at each step:
            1) Get sum[j ... n], the number of wires that started before i and finished after (or equal) j
            2) Add 1 to the position j
        
        Easy version: brute force for sum update
        Hard version: segtree for sum and update

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
const int N = 2e5+5;

int a[N], ps[N], n;

int query(int i, int j){
    return ps[j] - ps[i - 1];
}

void update(int i, int val){
    for(int j = i; j <= n; j++) ps[j] += val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            //get sum from [a[i] ... n]
            ans += query(a[i], n);
            //increment position a[i]
            update(a[i], 1);
        }
        cout << ans << "\n";

        //reset prefix sum
        for(int i = 1; i <= n; i++) ps[i] = 0;
    }
    return 0;
}