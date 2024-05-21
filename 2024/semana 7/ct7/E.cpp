#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> v(N);
//Basicamente, achar o maior segmento possivel de elem + e -, e somar
//o maximo elemento na resposta de cada segmento
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin>> v[i];
        int x=v[0]>=0?1:0,mx=v[0];
        long long ans=0;
        for(int i=1;i<n;i++){
            int y=v[i]>=0?1:0;
            if(!(x^y)) mx=max(mx,v[i]);
            else ans+=mx,mx=v[i],x=y;
        }
        ans+=mx;
        cout << ans << "\n";
    }

}