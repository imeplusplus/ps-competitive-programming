/*
    If you change the string to numbers, like:
        original order: 1, 2, 3, 4, 5 ...
        new order: 5, 3, 4, 1, ...
    The problem resumes to calculate the number of inversion count!!!

    You can use the old solution with merge sort, but there is an interesting solution with bit:

    Each position of the bit will represent a number, each value is the number of elements of that number
    Process the numbers and at each step i:
        Check how much elements are > i, this are the number of inversions for that position
        Add 1 to position i
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
const int N = 3e4+5;

int t, n;
map<string, int> id;

ll bit[N];

//changed the pos < N
void update(ll x, int pos) {
	while(pos < N) {
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
    cin >> t;
    while(t--){
        for(int i = 0; i < N; i++) bit[i] = 0;
        cin >> n;
        //map string to number
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            id[s] = i;
        }
        //process with bit
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            ans += rangesum(id[s] + 1, n + 1);
            update(1, id[s]);
        }
        cout << ans << "\n";
    }
    return 0;
}