#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> arr(N);
vector<int> ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ps.push_back(0);
    for(int i=1;i<=n;i++){
        ps.push_back(ps[i-1]+arr[i-1]);
    }
    pair<int,int> ans; //ans.st: value //ans.nd: range first index
    ans.first=ps[k]-ps[0]; ans.second=1;
    for(int i=1;i<=n-k;i++){
        int x=ps[i+k]-ps[i];
        if(ans.first>x){
            ans.first=x;
            ans.second=i+1;
        }
    }
    cout << ans.second << "\n";
}