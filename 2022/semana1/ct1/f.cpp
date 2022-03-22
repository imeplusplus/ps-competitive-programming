#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int resposta[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool erased = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            s.erase(s.begin() + i);
            erased = true;
            break;
        }
    }
    if(erased == false) s.erase(s.begin());
    cout << s << "\n";
    return 0;
}