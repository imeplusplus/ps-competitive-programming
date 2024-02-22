#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    long long y;
    char c;
    float f;
    double d;

    //NÃO MISTURAR CIN/COUT COM SCANF/PRINTF

    // scanf("%d %lld %c %f %lf", &x, &y, &c, &f, &d);
    // printf("%d\n%lld\n%c\n%.3f\n%.9lf\n", x, y, c, f, d);
    cin >> x >> y >> c >> f >> d;
    cout << x << "\n" << y << "\n" << c << "\n";
    cout << setprecision(3) << fixed << f << "\n";
    cout << setprecision(9) << fixed << d << "\n";
    return 0;
}
