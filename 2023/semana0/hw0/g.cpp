#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    /*  cuidado ao fazer mts ifs separados sem usar else if!
        dependendo da condição, pode ser que execute dois ou mais ifs */
    if(n > 9) printf("Greater than 9\n");
    if(n == 9) printf("nine\n");
    if(n == 8) printf("eight\n");
    if(n == 7) printf("seven\n");
    if(n == 6) printf("six\n");
    if(n == 5) printf("five\n");
    if(n == 4) printf("four\n");
    if(n == 3) printf("three\n");
    if(n == 2) printf("two\n");
    if(n == 1) printf("one\n");

    return 0;
}
