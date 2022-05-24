/*
    Key idea:
        Usual dp like:  dp[i]: max answer beginning (possibly) at position i
                        transition: dp[i] = max(dp[i + 1],                  going to the next planet without picking gems at planet i
                                                dp[i + k + 1] + r[i]        going to the next possible planet picking all gems
                                                dp[i + k/2 + 1] + r[i]/2)   going to the next possible planet picking only half gems
    
    Problem solved with a recursion, try to solve it in an iterative way.
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

int n, k, r[N], dp[N];

int calc(int pos){
    if(pos > n) return 0;
    if(dp[pos] != -1) return dp[pos];
    return dp[pos] = max({calc(pos + 1), r[pos]/2 + calc(pos + k/2 + 1), r[pos] + calc(pos + k + 1)});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> r[i];
    memset(dp, -1, sizeof(dp));
    cout << calc(1) << "\n";
    return 0;
}