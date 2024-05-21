#include <bits/stdc++.h>
using namespace std;
bool check=true;
struct Node{
    int cnt=0;
    int is_end_cnt=0;
    Node* ch[10];
    Node():cnt(0){
        memset(ch,0,sizeof(ch));
    }
    ~Node(){
      for(int i=0;i<10;i++){
        delete this->ch[i];
      }
   }
};
Node* root;
void add(string s){
    Node* cur=root;
    cur->cnt++;
    for(auto c : s){
        if(!cur->ch[c-'0']) cur->ch[c-'0']=new Node();
        cur=cur->ch[c-'0'];
        cur->cnt++;
        if(cur->cnt>1 and cur->is_end_cnt) check=false;
    }
    cur->is_end_cnt++;
    if(cur->cnt>1 and cur->is_end_cnt) check=false;
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    int t;
    cin >> t;
    while(t--){
        root=new Node();
        int n;
        cin >> n;
        check=true;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            add(s);
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
        delete root;
    }   
}