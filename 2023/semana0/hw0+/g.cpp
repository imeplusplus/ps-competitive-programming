#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        // na tabela ascii, os numeros estão em ordem
        // então se eu fizer a diferenca dos caractéres, acaba ficando com o numero que quero
        sum += s[i] - '0';
    }
    if(sum % 9 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}