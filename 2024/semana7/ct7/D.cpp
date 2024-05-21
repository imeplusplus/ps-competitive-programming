#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int arr[N];
vector<int> dp(N);
// Vamos definir nossa dp[i]: maximo de scores que consegue-se obter comecando no indice i
// No jogo: ao escolher um indice i para o cursor apontar, soma-se arr[i] no score
// Mas se arr[i]+i<n, entao pode-se apontar o cursor para o indice arr[i]+i
// Veja que se comecarmos pelo indice i=n, nunca que arr[i]+n < n, pois arr[i]>0
// entao nossa formula da dp eh: 
// dp[i]=arr[i], se arr[i]+i>n
// dp[i]=arr[i]+dp[arr[i]+i], caso contrario
// Bastar fazer a tabulacao de tras pra frente, pois voce sempre vai precisar de todos os posteriores
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        for(int i=n;i>=1;i--){
            if(i+arr[i]<=n) dp[i]=arr[i]+dp[i+arr[i]];
            else dp[i]=arr[i];
        }
        int ans=-1;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout << ans << "\n";
    }
   
}