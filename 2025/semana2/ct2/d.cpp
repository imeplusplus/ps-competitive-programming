#include <bits/stdc++.h>

using namespace std;
const int N = 55;
typedef long long ll;
int m[N][N], cp[N][N], n;

void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cp[i][j] = m[j][n - i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = cp[i][j];
        }
    }
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (m[i][j] > m[i][j + 1]) return false;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] > m[i + 1][j]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> m[i][j];
    while (!check()) {
        rotate();
        cnt++;
    }
    cout << cnt;
}