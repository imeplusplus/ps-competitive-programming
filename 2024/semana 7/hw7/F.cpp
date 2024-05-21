#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int m[N][N];
int ps[N+1][N+1];

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin >> c;
            if(c=='*') m[i][j]=1;
            else m[i][j]=0; 
        }
    }
    //Inicializar a linha 0 e a coluna 0 com '0' na matriz de prefixo
    memset(ps,0,sizeof(ps));
    //Montar linha a linha a matriz de prefixo, para montar a linha i, vamos precisar da linha i-1 preenchida
    // e do elemento imediatamente da linha i (ai j-1)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+m[i][j];
        }
    }
    //Formula para a query
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ps[x2][y2]-ps[x2][y1-1]-ps[x1-1][y2]+ps[x1-1][y1-1] << "\n";
    }
}