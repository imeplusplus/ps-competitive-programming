#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int shops[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //vector <int> shops(n)
    for(int i = 0; i < n; i++){
        cin >> shops[i];
    }
    //sort(shops.begin(), shops.end());
    sort(shops, shops + n);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        int distance = (upper_bound(shops, shops + n, x) - shops);
        //int distance = (upper_bound(shops.begin(), shops.end() + n, x) - shops.begin());
        cout << distance << "\n";
    }
    return 0;
}