#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

ld n;
int t;

// If you use pow() for integer exponents you'll get a WA someday
ld fexp(ld x, int y){
	ld r = 1;
	while(y){
		if(y & 1)
			r *= x;
		x *= x;
		y >>= 1;
	}
	return r;
}

int main(){
	scanf("%Lf %d", &n, &t);
	printf("%.15Lf\n", n * fexp(1.000000011, t));
}
