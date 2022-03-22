//not finished
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int gifts[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> gifts[i];
    }
    vector<int> auto_presente, falta_receber;
    //cuida dos caras que podem se auto presentear
    for(int i = 0; i < auto_presente.size(); i++){
        //por que usar o mod?
        gifts[auto_presente[i]] = auto_presente[(i + 1) % auto_presente.size()];
    }
    return 0;
}