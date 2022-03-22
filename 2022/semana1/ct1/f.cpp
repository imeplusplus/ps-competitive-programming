#include <bits/stdc++.h>

using namespace std;

//para que o número seja o maior possivel, basta deletar o primeiro zero
//caso não tenha zero, deleta qualquer "1"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
						//apaga o primeiro zero q achar
            s.erase(s.begin() + i);
            cout << s << "\n";
            return 0;
        }
    }
		//se n achar zero, deleta qualquer 1
    s.erase(s.begin());
    cout << s << "\n";
    return 0;
}