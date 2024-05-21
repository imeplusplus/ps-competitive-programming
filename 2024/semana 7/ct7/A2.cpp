#include <bits/stdc++.h>
using namespace std;
int w;
int weight[65];
//Solucao meio feia, basicamente um knapsack fazendo uma analogia com o problema do troco
//Porem deu memory limit exceed :(
void generate(){
    vector<int> pow;
    int p=1,i=0;
    for(int i=0;i<6;i++){
        pow.push_back(p);
        p=p*10;
    }
    for(int a=0;a<=1;a++){
        for(int b=0;b<=1;b++){
            for(int c=0;c<=1;c++){
                for(int d=0;d<=1;d++){
                    for(int e=0;e<=1;e++)
                        for(int f=0;f<=1;f++){
                            weight[i++]=(f*pow[0]+e*pow[1]+d*pow[2]+c*pow[3]+b*pow[4]+a*pow[5]);
                        }
                }
            }
        }
    }
    weight[i++]=(10*pow[5]);

}
void recover(int l,int c,vector<vector<int>> &r){
    if(l==0) return;
    if(r[l][c]>1e9-5) recover(l-1,c,r);
    else{
        cout << weight[r[l][c]] << " ";
        recover(l,c-weight[r[l][c]],r);
    }
}
int main(){
    generate();
    cin >> w;
    vector<vector<int>> dp(66,vector<int>(w+1,1e9)),rec(66,vector<int>(w+1,1e9));
    for(int i=0;i<66;i++) dp[i][0]=0;
    for(int i=1;i<=65;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                if(1+dp[i][j-weight[i-1]]<dp[i-1][j]){
                    dp[i][j]=1+dp[i][j-weight[i-1]];
                    rec[i][j]=i-1;
                }
                else dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    int ans=dp[65][w];
    dp.clear();
    cout << ans << "\n";
    recover(65,w,rec);
}