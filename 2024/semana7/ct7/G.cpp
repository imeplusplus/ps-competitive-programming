#include <bits/stdc++.h>
using namespace std;
const int N=105,INF=1e9;
int arr[N];
vector<int> adj[4];
void setAdj(){
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(1);
}
// Nossa dp[i][j]: numero de dias que ele descansou do dia 0 a i,dado q ele fez a atividade j no dia i
// O primeiro dia de ferias eh o dia 0
// j=0 representa q ele descansou naquele dia, j=1 que ele foi pro contest, j=2 q ele foi pra gym
int main(){
    setAdj();
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<vector<int>> dp(n,vector<int>(3));
    // Montar nossa matriz com INF nos dias que nao pode exercer tal atividade, baseado no array
    for(int i=0;i<n;i++){
        for(auto k : adj[arr[i]]) dp[i][k]=INF;
    }
    // Nosso caso base seria apenas o primeiro elemento do array
    for(int i=0;i<3;i++){
        if(dp[0][i]!=INF){
            if(!i) dp[0][i]=1;
        }
    }
    // Nossa tabulacao
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(dp[i][j]!=INF){
                if(!j) dp[i][j]=min(1+dp[i-1][0],min(1+dp[i-1][1],1+dp[i-1][2]));
                else if(j==1) dp[i][j]=min(dp[i-1][0],dp[i-1][2]);
                else if(j==2) dp[i][j]=min(dp[i-1][0],dp[i-1][1]);
            }
        }
    }
    int ans=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    cout << ans << "\n";
}