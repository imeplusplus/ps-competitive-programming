#include <bits/stdc++.h>
using namespace std;
void solve(string s){
    int t=1,ans=0;
    bool check=false;
    for(int i=s.size()-1;i>=0;i--){
        int x=s[i]-'0';
        if(x) ans+=t,check=true,s[i]--;
        t*=10;
    }
    if(!check) return;
    else{
        cout << ans << " ";
        solve(s);
    }
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    string s;
    cin >> s;
    int sz=0;
    for(auto x : s) sz=max(sz,(int)(x-'0'));
    cout << sz << "\n";
    solve(s);
}