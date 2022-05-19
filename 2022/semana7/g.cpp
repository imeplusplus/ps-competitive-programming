/*
    The idea is to use a bit to simulate the multiset
    Each position 'i' from bit will tell how many 'i's we have in our multiset
    
    Add operation: just update the bit
    Remove operation: binary search on bit

    Total Complexity: O(n * logn * logn)
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
int n, q;

//bit
int bit[N];
void update(int x, int pos) {
	while(pos <= n) {
		bit[pos] += x;
		pos += pos&(-pos);
	}
}

int query(int pos) {
	int r = 0;
	while(pos) {
		r+= bit[pos];
		pos -= pos&(-pos);
	}
	return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update(1, x);
    }
    for(int i = 1; i <= q; i++){
        int k;
        cin >> k;
        //insert in multiset
        if(k > 0){
            update(1, k);
        }
        else{
            //change k just to fit better
            k = abs(k);
            //lets try to guess which number is the k-th order
            //if the sum until k is equal or greater, then this answer may be possible: r = mid
            //if the sum until k is lesser, then this answer may not even be possible: l = mid + 1
            int l = 1, r = n;
            while(l < r){
                int mid = (l + r)/2;
                if(query(mid) >= k) r = mid;
                else l = mid + 1;
            }
            //remove the found number from multiset
            update(-1, l);
        }   
    }
    //check naively if there is still anything in the multiset
    for(int i = 1; i <= n; i++){
        if(query(i) > 0) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}