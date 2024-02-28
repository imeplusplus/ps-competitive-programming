#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // pensar em como numeros de base maior funcionam
    // nesse caso pensar como se fosse um numero na base 26
    string s;
    cin >> s;
    long long ans = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        ans *= 26;
        ans += s[i] - 'A' + 1;
    }
    cout << ans << "\n";
    return 0;
}