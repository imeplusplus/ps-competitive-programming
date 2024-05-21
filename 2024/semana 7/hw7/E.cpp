#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> arr(N);
vector<long long> ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ps.push_back(0);
    for(int i=1;i<=n;i++){
        ps.push_back(ps[i-1]+arr[i-1]);
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << ps[r]-ps[l-1] << "\n";
    }
}