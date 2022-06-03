#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int a[N], trade[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, int> number;
    int pos1 = -1, pos2 = -1;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        //busca k - x
        if(number.count(k - x)){
            //existe resposta
            pos1 = i;
            pos2 = number[k - x];
        }
        //insere no map
        number[x] = i;
    }
    //verifica se achou resposta
    if(pos1 == -1) cout << "-1\n";
    else cout << pos1 << " " << pos2 << "\n";
    return 0;
}


//outra ideia é usar um array de pair, onde o first é o valor
//e o second é a posição original. Faz-se entao busca binária e 
//retorna o second
/*
int n, x;
pair<int, int> v[N];

int b_srch(int l, int r, int val){
	int mid = (l+r)/2;
	while(l<r){
		if(v[mid].first < val) l = mid+1;
		else r = mid;
		mid = (l+r)/2;
	}
	return mid;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> x;
	for(int i = 0; i<n; i++){
		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(v, v+n);
	for(int i = 0; i<n-1; i++){
		//é possivel usar o lower_bound() - Lembrando que ela retorna um PONTEIRO
		//fazer a busca sempre a partir do i+1 pra evitar pegar a mesma posição
		//auto aux = lower_bound(v+i+1, v+n, make_pair(x-v[i].first, 0));
		int aux = b_srch(i+1, n-1, x-v[i].first);
		if((v[i].first + v[aux].first == x)){ // ou: v[i].first + (*aux).first == x
			cout << v[i].second << " " << v[aux].second << '\n';
			//cout << v[i].second << " " << (*aux).second << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
/*