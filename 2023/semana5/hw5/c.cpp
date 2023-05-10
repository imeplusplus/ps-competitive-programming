// complexidade do codigo: O(nlogn)

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        int x, n;
        cin >> x >> n;
        int curAns = n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        set<int> positions;
        map<int, int> sizes;
        // no começo é como se eu tivesse duas luzes nas extremidades
        // então tenho um segmento de tamanho x não iluminado
        positions.insert(0);
        positions.insert(x);
        sizes[x] = 1;
        for(int i = 0; i < n; i++) {
            auto itr = positions.upper_bound(p[i]);
            auto prev_itr = itr;
            prev_itr--; // não precisamos checar se prev_itr == positions.begin() sempre tem pelo menos o elemento 0
            int leftVal = *prev_itr, rightVal = *itr;
            int leftSize = p[i] - leftVal, rightSize = rightVal - p[i];
            // retiro o segmento de tamanho rightVal - leftVal
            // e adiciono dois segmentos de tamanho leftSize e rightSize
            sizes[rightVal - leftVal]--;
            if(sizes[rightVal - leftVal] == 0)
                sizes.erase(rightVal - leftVal);
            sizes[leftSize]++;
            sizes[rightSize]++;
            positions.insert(p[i]);
            cout << sizes.rbegin()->first << " ";
        }
    }
    return 0;
}