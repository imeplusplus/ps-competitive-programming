#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s]++;
            if(mp[s] == 1) {
                // ngm tem esse nome
                cout << "OK" << endl;
            } else {
                // agora tem mp[s] pessoas com esse nome
                // então o nome vai ser s concatenado com mp[s] - 1.
                // como so vamos printar, não precisa transformar int em string
                cout << s << mp[s] - 1 << endl;
            }
        }
        
    }
    return 0;
}