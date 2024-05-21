#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
// Dado um array, achar o tamanho do maior subarray que os elementos estao em ordem nao decrescente
// Basicamente um kadane modificado
// Comeca de tras pra frente, se o array terminasse em [arr[n]], entao a resposta seria 1
// Se arr[n-1]<=arr[n] entao a resposta seria 2
// Se arr[n-1]>arr[n] entao a resposta passa a ser 1 tb
// Tome o ex: 2 2 1 3 4 1
// [1] -> 1
// [4 1] -> 1
// [3 4 1] -> 2, pois 3<=4
// [1 3 4 1] -> 3,pois 1<=3,entao soma +1 na resposta anterior
// [2 1 3 4 1] -> 3, mas 2>3, entao nao soma +1 na resposta, mas ainda podemos pegar o maximo dos anteriores
// [2 2 1 3 4 1] -> 3, apesar de 2<=2, a sub sequencia [2 2] nao tem tamanho maior que 3
// Bizu: cur eh o tamanho do subarray q vc achou anaquele momento, ans eh o tamanho do maior subarray que voce ja achou
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    vector<int> dp(N);
    int ans=1,cur=1;
    dp[n]=1;
    for(int i=n-1;i>=1;i--){
        if(arr[i]<=arr[i+1]) cur++;
        else cur=1;
        ans=max(ans,cur);
    }
    cout << ans << "\n";

}