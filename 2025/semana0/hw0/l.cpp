#include <bits/stdc++.h>

using namespace std;

int main(){
    int resposta;
    for(int i = 1; i <= 5; i++){
        int x;
        scanf("%d", &x);
        if(x == 0) resposta = i;
    }
    printf("%d\n", resposta);
    return 0;
}
