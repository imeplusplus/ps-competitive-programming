#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const long long INF=1e18;
vector<int> arr(N);
vector<int> ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ps.push_back(0);
    for(int i=1;i<=n;i++){
        ps.push_back(ps[i-1]+arr[i-1]);
    }
    set<int> s;
    long long ans=-INF;
    for(int i=0;i<=n;i++){
        s.insert(ps[i]);
        auto itr=s.begin();
        int x=ps[i]-*itr;
        if(ans<x) ans=x;
    }
    cout << ans << "\n";
}