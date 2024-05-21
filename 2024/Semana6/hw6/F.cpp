#include <bits/stdc++.h>
using namespace std;
const int p=31;
const int m=1e9+9;
// Printar o tamanho dos prefixos que tambem sao sufixos
// Ex: abcababcab tem como prefixo que tb eh sufixo "ab" e "abcabc" ( 2 e 5 )
// ababa "aba" eh prefixo e sufixo (aba)ba e ab(aba)
// Nao vale se for a propria string
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    string s;
    cin >> s;
    vector<long long> pi(s.size()+1),p_pot(s.size());
    p_pot[0]=1;
    for(int i=1;i<s.size();i++) p_pot[i]=(p_pot[i-1] * p) % m;
    for(int i=0;i<s.size();i++) pi[i+1]=(pi[i] + (s[i]-'a'+1)*p_pot[i]) % m;
    for(int i=1;i<(s.size());i++){
        long long pre=pi[i];
        long long suf=(pi[s.size()] - pi[s.size()-i] + m) % m;
        if((pre * p_pot[s.size()-i]) % m == suf) cout << i << " ";
    }

}