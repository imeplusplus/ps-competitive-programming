#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int arr[N],v[N];
// Sliding Window padrao
// Dado um array A, montar um array B, onde b[i]=1 se b[i]>b[i+1] e b[i]>b[i-1], b[i]=0 c.c
// Achar a maior soma numa janela (l,l+k-1), onde l e l+k-1 sao nao inclusivos 
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        memset(v,0,sizeof(v));
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> arr[i];
        for(int i=2;i<n;i++){
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]) v[i]=1;
        }
        int l=2,r=l+(k-3),cur=0;
        for(int i=l;i<=r;i++) cur+=v[i];
        pair<int,int> ans={cur,2};
        l++;r++;
        while(r<=n){
            cur-=v[l-1];
            cur+=v[r];
            if(cur>ans.first){
                ans.first=cur;
                ans.second=l;
            }
            r++;l++;
        }
        cout << ans.first+1 << " " << ans.second-1 << "\n";
    }
}