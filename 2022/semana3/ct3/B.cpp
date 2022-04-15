// If we play until time t we loose t of energy in total
// (1 joystick loosing 2% and 1 gaining 1%)
// So a1 + a2 - t >= 0, t <= a1 + a2 <= 200

// Solution
// Simulate the game, giving energy to the one that has less energy
// O(a1 + a2)
// Atention for the corner case of a1 = a2 = 1

#include<bits/stdc++.h>
using namespace std;

int a1, a2, t;

int main(){
    scanf("%d %d", &a1, &a2);
    while(a1 > 0 && a2 > 0 && (a1 > 1 || a2 > 1)){
    	t++;
    	if(a1 < a2){
    		a1++;
    		a2 -= 2;
    	}
    	else{
    		a2++;
    		a1 -= 2;
    	}
	}
	printf("%d\n", t);
    return 0;
}
