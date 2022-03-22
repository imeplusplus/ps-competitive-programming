#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int f[n];
	//set de quem falta receber, e quem falta dar
	set<int> giv, rec;
	//primeiro todo mundo falta receber. Conforme vai lendo, apaga quem recebeu
	for(int i = 0; i<n; i++) rec.insert(i+1);
	for(int i = 0; i<n; i++){
		cin >> f[i];
		if(f[i] == 0) giv.insert(i+1);
		rec.erase(f[i]);
	}
	//primeiro, acha quem ta isolado(não recebeu nem deu ainda) e faz ele dar pra alguem que tb tá isolado
	set<int> isolated;
	for(auto i = giv.begin(); i!=giv.end(); i++) if(rec.count(*i)) isolated.insert(*i);
	while(isolated.size() > 1){
		auto a = isolated.begin();
		auto b = a;
		b++;
		f[(*a)-1] = *b;
		giv.erase(*a);
		isolated.erase(a);
		rec.erase(*b);
		isolated.erase(b);
	}
	//se ainda tiver alguem isolado, faz dar pra alguem que não si msm
	if(isolated.size()){
		auto a = isolated.begin();
		auto b = rec.begin();
		if(*a == *b) b++;
		f[(*a)-1] = *b;
		giv.erase(*a);
		rec.erase(*b);
		isolated.erase(a);
	}
	//agora, como é impossivel se dar um presente, basta dar pra alguem que não recebeu ainda
	while(!giv.empty()){
		auto aux = giv.begin();
		auto aux1 = rec.begin();
		f[(*aux)-1] = *aux1;
		giv.erase(aux);
		rec.erase(aux1); 
	}
	for(int i = 0; i<n; i++) cout << f[i] << " ";
	cout << '\n';
	return 0;
}