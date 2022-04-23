// Solution
// Check every position to put a bomb
// To check it fast, precalculate the number of walls
// and the number of walls in each column and each row

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, row[N], col[N], walls;
char grid[N][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf(" %c", &grid[i][j]);
			row[i] += (grid[i][j] == '*');
			col[j] += (grid[i][j] == '*');
			walls  += (grid[i][j] == '*');
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(row[i] + col[j] - (grid[i][j] == '*') == walls){
				printf("YES\n%d %d\n", i + 1, j + 1);
				return 0;
			}
	printf("NO\n");
	return 0;
}
