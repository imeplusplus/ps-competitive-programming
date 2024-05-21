#include <bits/stdc++.h>
using namespace std;
const int p=31;
const int m=1e9+9;
// Algoritmo de Rabin-Karp: Achar quantas vezes aparece uma string T numa string S(Achar padroes)
// Ex: quantas vezes aparece "ab" em "ababab"
// 1-) Vamos fazer uma um vector pi para a string S, onde, pi[0]=0 e pi[i+1]=(s[0]+s[1]*p+...+s[i]*p^i)%m
// usando claro a ideia de prefixsum
// 2-) Vamos pre calcular o hash da string T e guarda-lo numa variavel
// 3-) Se (pi[i+T+1] - pi[i] + m) % m for igual a (hash(T)*p^i) % m entao o hash da substr
// "s[i+1]...s[i+T]" coincide com o hash da string T
// Obs: Em "(pi[i+T+1] - pi[i] + m) % m" o +m eh para evitar resto negativo
vector<long long> string_hash_pi(string s){
    vector<long long> pi(1);
    long long p_pow=1;
    for(int i=1;i<=s.size();i++){
        pi.push_back((pi[i-1]+(s[i-1]-'a'+1)*p_pow)%m);
        p_pow=(p_pow*p)%m;
    }
    return pi;
}
long long string_hash_value(string s){
    long long hash_value=0;
    long long p_pow=1;
    for(char c : s){
        hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
        p_pow=(p_pow*p)%m;
    }
    return hash_value;
}
// string s
// s.substr(i,n) -> pega a substing comecando em s[i] de tamanho n
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    int n;
    cin >> n;
    while(n--){
        string s,t;
        cin >> s >> t;
        int a=s.size(),b=t.size();
        if(b>a) cout << "Not Found\n";
        else{
            vector<int> pos;
            long long cnt=0,x=string_hash_value(t),p_pow=1;
            vector<long long> pi=string_hash_pi(s);
            for(int i=0;i<=a-b;i++){
                if((pi[i+b]-pi[i]+m)%m==(x*p_pow)%m){
                    cnt++;
                    pos.push_back(i+1);
                }
                p_pow=(p_pow*p)%m;
            }
            if(!cnt) cout << "Not Found\n";
            else{
                cout << cnt << "\n";
                for(auto x : pos) cout << x << " ";
                cout << "\n";
            }
            if(n) cout << "\n";
        }
        
    }
}