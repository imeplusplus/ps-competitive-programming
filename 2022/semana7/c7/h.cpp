/*
    Key idea:
        Two pointers l, r to brute force middle string size
        Use prefix sum to calculate how many characters should be removed

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
const int N = 5e3+5;

int ps[2][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    //lets define by convention: ps[i] = sum[0 ... i);
    for(int i = 1; i <= s.size(); i++){
        //load last prefix sum
        ps[0][i] = ps[0][i - 1];
        ps[1][i] = ps[1][i - 1];
        
        //sum
        if(s[i - 1] == 'a') ps[0][i]++;
        else ps[1][i]++;
    }

    //two pointers to search for the answer
    //[0 ... l) string of a's
    //[l ... r] string of b's
    //(r ... n] string of a's
    int ans = 0;
    for(int l = 0; l < s.size(); l++){
        for(int r = l; r < s.size(); r++){
            int rem = 0;
            //remove b's from first string
            rem += ps[1][l];
            //remove a's from second string
            rem += ps[0][r + 1] - ps[0][l];
            //remove b's from third string
            rem += ps[1][s.size()] - ps[1][r + 1];
            ans = max((int)s.size() - rem, ans);
        }
    }

    //last fors do not consider strings only with a's
    ans = max(ans, (int)s.size() - ps[1][s.size()]);
    cout << ans << "\n";
    return 0;
}