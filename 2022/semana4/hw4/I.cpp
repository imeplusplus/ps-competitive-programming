// Solution
// Edit Distance is similar to LCS
// #1: ed[i][j] = Edit Distance of prefix until i of A and until j of B
// #2: if(A[i] == B[j]) ed[i][j] = ed[i - 1][j - 1]
//     else ed[i][j] = min(ed[i - 1][j] + 1 if we delete A[i] or add A[i] to B,
//                         ed[i][j - 1] + 1 if we delete B[j] or add B[j] to A,
//                         ed[i - 1][j - 1] + 1 if we change A[i] to B[j] or B[j] to A[i])
// There isn't an obvious best opition, deleting a character can make more "matches"

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int t, ed[N][N], ta, tb;
char a[N], b[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf(" %s", a);
		ta = strlen(a);
		scanf(" %s", b);
		tb = strlen(b);
		// Index it by 1, set ed[i][0] = i and ed[0][j] = j
		for(int i = 1; i <= ta; i++)
			ed[i][0] = i;
		for(int j = 1; j <= tb; j++)
			ed[0][j] = j;
		for(int i = 1; i <= ta; i++)
			for(int j = 1; j <= tb; j++){
				if(a[i - 1] == b[j - 1])
					ed[i][j] = ed[i - 1][j - 1];
				else
					ed[i][j] = min({ed[i - 1][j] + 1,
									ed[i][j - 1] + 1,
									ed[i - 1][j - 1] + 1});
			}
		printf("%d\n", ed[ta][tb]);
	}
	return 0;
}
