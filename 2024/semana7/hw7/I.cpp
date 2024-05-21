#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
vector<long long> arr;
vector<long long> ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        for(int i=0;i<n;i++){
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        ps.push_back(0);
        for(int i=1;i<=n;i++){
            ps.push_back(ps[i-1]+arr[i-1]);
        }
        set<long long> s;
        long long ans=-INF;
        for(int i=0;i<=n;i++){
            s.insert(ps[i]);
            auto itr=s.begin();
            long long x=ps[i]-*itr;
            if(ans<x) ans=x;
        }
        if(ans>0) cout << "The maximum winning streak is " << ans<< ".\n";
        else cout << "Losing streak.\n";
        arr.clear(); ps.clear();
    }
}