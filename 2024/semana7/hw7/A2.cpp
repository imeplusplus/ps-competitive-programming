#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int v[N];
//Dado um array, achar o maior valor da soma de um subarray, Algoritmo de Kadane
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    long long ans=0,cur=0;
    for(int i=0;i<n;i++){
        cur+=v[i];
        if(cur<0) cur=0;
        ans=max(ans,cur);
}
    cout << ans << "\n";
}