// dfs from each intersection
// checks if got to each other intersection

#include<bits/stdc++.h>
using namespace std;

const int N = 25;

int n, m, h, vis[N][N];
char horD[N], verD[N];

int dfs(int x, int y){
	// Checks if out of the grid or already visited
	if(x <= 0 || x > n || y <= 0 || y > m || vis[x][y] == h)
		return 0;
		
	int r = 1;
	vis[x][y] = h;
	
	// Horizontal Direction
	if(horD[x] == '>')
		r += dfs(x, y + 1);
	else
		r += dfs(x, y - 1);
		
	// Vertical Direction
	if(verD[y] == '^')
		r += dfs(x - 1, y);
	else
		r += dfs(x + 1, y);
		
	return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
	for(int i = 1; i <= n; i++)
        cin >> horD[i];
	for(int i = 1; i <= m; i++)
        cin >> verD[i];
	
	// Iterate over every intersection
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			h++;
			// Checks if pass through every intersection
			if(dfs(i, j) < n * m){
				cout << "NO\n";
				return 0;
			}
		}
    cout << "YES\n";
    return 0;
}
