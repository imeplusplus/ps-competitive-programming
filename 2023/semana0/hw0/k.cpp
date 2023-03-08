#include <bits/stdc++.h>

using namespace std;

int v[1005];

int main(){
    int n = 0, i = 0;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    for(i = n - 1; i >= 0; i--){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}
