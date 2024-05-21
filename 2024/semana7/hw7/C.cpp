#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> arr(N);
int dp[N];

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout << dp[n] << "\n";
}