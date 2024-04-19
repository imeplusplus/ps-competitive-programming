#include<bits/stdc++.h>
using namespace std;

//ambas soluções com complexidade O(nlog(n))
//solução com set

// int main(){
// 	cin.tie(NULL);
// 	ios_base::sync_with_stdio(false);
// 	int t;
// 	set<int> s;
// 	cin >> t;
// 	for(int i = 0; i < t; i++){
// 		int a;
// 		cin >> a;
// 		s.insert(a);
// 	}
// 	cout << s.size() << '\n';
// 	return 0;
// }



//solução com unique
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int N = 2e5 + 5;
    int v[N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);
    cout << unique(v, v + n) - v << '\n';
    return 0;
}
