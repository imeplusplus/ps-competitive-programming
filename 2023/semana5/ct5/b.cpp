#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d;
    cin >> n >> d;
    int t[n];
    for(int i = 0; i < n; i++)
        cin >> t[i];

    // binary search no numero de computadores necessarios
    int l = 1, r = n;
    while(l != r) {
        // heap pra colocar o tempo que cada um vai terminar
        priority_queue<int, vector<int>, greater<int>> pq;
        int mid = (l + r) / 2;
        // coloco só os M primeiros no começo
        for(int i = 0; i < mid; i++)
            pq.push(t[i]);
        int ptr = mid, cur = 0;
        while(!pq.empty()) {
            cur = pq.top();
            pq.pop();
            // se ainda tem alguem na fila, eu coloco que ele vai terminar no tempo cur + t[ptr]
            // pois cur é o tempo que eu coloco ele e t[ptr] o que ele demora
            if(ptr < n)
                pq.push(cur + t[ptr++]);
        }
        if(cur > d) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}