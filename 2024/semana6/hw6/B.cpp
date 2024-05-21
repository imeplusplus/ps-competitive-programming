#include <bits/stdc++.h>
using namespace std;
string s;
// Basicamente, montar a Trie
// Na hora de fazer as queries basta fazer um dfs na arvore
// 1-) Faca um match, para chegar no no que termina o prefixo
// 2-) Agora, resta basicamente fazer um backtracking:
// Node* cur; cur->filho[i] acrescenta o caracter na string ate chegar numa folha
// Quando chegar na folha, printa a string e voltar para cur, reverte a string para o estado inicial
// E faca o mesmo procedimento pro cur->filho[i+1]
struct Node{
    int is_end_cnt=0;
    Node* ch[26];
    Node(){
         memset(ch,0,sizeof(ch));
    }
};
Node* root;
void add(string s){
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) cur->ch[c-'a']=new Node();
        cur=cur->ch[c-'a'];
    }
    cur->is_end_cnt++;
}
Node* match(string s) {
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) return NULL;
        cur=cur->ch[c-'a'];
    }
    return cur;
}
void dfs(Node* cur,int k){
    if(cur==NULL){ 
        cout << "No match.\n";
        return;
    }
    if(cur->is_end_cnt and k) cout << s << "\n";
    for(int i=0;i<26;i++){
        if(cur->ch[i]!=NULL){
            string aux=s;
            s+=(char)(i+97);
            dfs(cur->ch[i],k+1);
            s=aux;
        } 
    }
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    root=new Node();
    int n;
    cin >> n;
    while(n--){
        cin >> s;
        add(s);
    }   
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> s;
        cout << "Case #" << i << ":\n";
        dfs(match(s),0);
    }
}