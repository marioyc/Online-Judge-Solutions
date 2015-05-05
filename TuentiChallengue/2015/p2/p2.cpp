#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100000000

int pdiv[MAXN + 1],cont[MAXN + 1];

int main(){
	memset(pdiv,-1,sizeof pdiv);

	cont[0] = cont[1] = 0;

	for(int i = 2;i <= MAXN;++i){
		if(pdiv[i] == -1){
			pdiv[i] = i;
			cont[i] = 0;

			if(i <= MAXN / i)
				for(int j = i * i;j <= MAXN;j += i)
					pdiv[j] = i;
			
		}else{
			int aux = i / pdiv[i];

			cont[i] = (pdiv[aux] == aux? 1 : 0);
		}
	}

	for(int i = 2;i <= MAXN;++i)
		cont[i] += cont[i - 1];

	int T,A,B;

	cin >> T;

	while(T--){
		cin >> A >> B;
		cout << cont[B] - cont[A - 1] << '\n';
	}

	return 0;
}