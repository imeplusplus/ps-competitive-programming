#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> arr(N),arr2(N);
vector<int> ps,ps2;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,k,q;
    cin >> n >> k >> q;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        arr[l]+=1;
        arr[r+1]-=1;
    }
    //Vamos usar a ideia de update in range pra montar o um array, tq o ps desse array
    //vai ser: ps[i]:numero de vezes que uma receita citou a temperatura i
    ps.push_back(0);
    for(int i=1;i<=N;i++) ps.push_back(ps[i-1]+arr[i]);
    //Agora vamos montar um array auxiliar arr2, onde arr2[i]==1, se a temperatura i foi citada 
    //em pelo menos k receitas, ou seja, se a temperatura i eh otima para o cafe e arr2[i]==0 c.c.
    for(int i=1;i<=N;i++) if(ps[i]>=k) arr2[i]=1;
    //Agora vamos montar o ps do arr2, onde: ps2[i]: numero de temperaturas otimas no intervalo [1,i]
    ps2.push_back(0);
    for(int i=1;i<=N;i++) ps2.push_back(ps2[i-1]+arr2[i]);
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << ps2[r] - ps2[l-1] << "\n";
    } 
}