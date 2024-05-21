#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int board[17][N][N],ps[17][N][N];
// I hate multidimensional arrays
// Basicamente: Eh um prefix sum 2d padrao, porem as entradas da matriz variam conforme o tempo
// Entao voce tem que fazer uma matriz board e uma matriz ps para cada tempo t
// Como se si(t)+1>c, entao si(t+1)=0, ha uma periodicidade
// Por isso precisamos de um array 3 dimensional, pois vamos pontar uma matriz board e uma matriz ps para
// cada um dos tempos ate o periodo
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    memset(board,0,sizeof(board));
    int n,q,c;
    cin >> n >> q >> c;
    for(int k=0;k<n;k++){
        int x,y,s;
        cin >> x >> y >> s;
        for(int i=0;i<c+1;i++) board[i][x][y]+=(s+i)%(c+1);
        //Cuidado: nao fazer board[i+1][x][y]=(board[i][x][y]+1)%(c+1) :(
    }
    memset(ps,0,sizeof(ps));
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=0;k<=c;k++){
                ps[k][i][j]=ps[k][i-1][j]+ps[k][i][j-1]-ps[k][i-1][j-1]+board[k][i][j];
            }
        }
    }
    for(int i=0;i<q;i++){
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        long long aux=ps[t%(c+1)][x2][y2]-ps[t%(c+1)][x2][y1-1]-ps[t%(c+1)][x1-1][y2]+ps[t%(c+1)][x1-1][y1-1];
        cout << aux << "\n";
    }
}