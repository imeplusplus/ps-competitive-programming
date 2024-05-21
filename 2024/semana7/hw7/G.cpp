#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> arr;
vector<long long> ps1,ps2;


int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    ps1.push_back(0); ps2.push_back(0);
    for(int i=1;i<=n;i++){
        ps1.push_back(ps1[i-1]+arr[i-1]);
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<=n;i++){
        ps2.push_back(ps2[i-1]+arr[i-1]);
    }
    cin >> q;    
    for(int i=0;i<q;i++){
        int t,l,r;
        cin >> t >> l >> r;
        if(t==1) cout << ps1[r]-ps1[l-1] << "\n";
        else cout << ps2[r]-ps2[l-1] << "\n";
    }
}