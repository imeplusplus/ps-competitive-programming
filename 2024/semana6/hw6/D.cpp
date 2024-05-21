#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
unordered_map<string,int> mp;
string s;
struct Node{
    int occ=0;
    string str;
    Node* ch[26];
    Node(){
        memset(ch,0,sizeof(ch));
    }
};
Node* root;
void add(string s,int cnt){
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) cur->ch[c-'a']=new Node();
        cur=cur->ch[c-'a'];
        if(cnt>cur->occ){
            cur->str=s;
            cur->occ=cnt;
        }
        else if(cnt==cur->occ){
            if(s<cur->str) cur->str=s;
        }
    }
}
Node* match(string s){
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) return NULL;
        cur=cur->ch[c-'a'];
    }
    return cur;
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    root=new Node();
    int n,m;
    cin >> n;
    while(n--){
        cin >> s;
        if(mp.find(s)==mp.end()) mp[s]=1;
        else mp[s]++;
        add(s,mp[s]);
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> s;
        Node* aux=match(s);
        if(!aux) cout << -1 << "\n";
        else cout << aux->str << " " << aux->occ << "\n";
    }
    return 0;
}