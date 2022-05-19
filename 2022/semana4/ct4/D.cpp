// Solution
// Brute force it

#include<bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y){}
	
	point operator +(point o){
		return point(x + o.x, y + o.y);
	}
	
	bool operator ==(point o){
		return x == o.x && y == o.y;
	}
};

point p[3], aux[4] = {point(0, 1), point(0, -1), point(1, 0), point(-1, 0)};

int sqrDist(point p0, point p1){
	return (p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y);
}

bool right(point p0, point p1, point p2){
	// get the squared sides
	int l0 = sqrDist(p0, p1);
	int l1 = sqrDist(p0, p2);
	int l2 = sqrDist(p2, p1);
	
	// check for degeneracy
	if(p0 == p1 || p0 == p2 || p1 == p2)
		return false;
	
	// check for right angle
	return l0 == l1 + l2 || l1 == l0 + l2 || l2 == l0 + l1;
}

bool almostRight(point p0, point p1, point p2){
	// brute force the options
	for(int i = 0; i < 4; i++)
		if(right(p0 + aux[i], p1, p2))
			return true;
	for(int i = 0; i < 4; i++)
		if(right(p0, p1 + aux[i], p2))
			return true;
	for(int i = 0; i < 4; i++)
		if(right(p0, p1, p2 + aux[i]))
			return true;
	return false;
}

int main(){
	for(int i = 0; i < 3; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	if(right(p[0], p[1], p[2]))
		printf("RIGHT\n");
	else if(almostRight(p[0], p[1], p[2]))
		printf("ALMOST\n");
	else
		printf("NEITHER\n");
	return 0;
}
