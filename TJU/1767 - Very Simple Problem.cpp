#include <cstdio>

using namespace std;

int main(){
	int N,P;
	scanf("%d %d",&N,&P);
	
	int comp[N][P],min[N],max[N];
	
	for(int i = 0;i<N;++i)
		for(int j = 0;j<P;++j)
			scanf("%d",&comp[i][j]);
	
	for(int i = 0;i<N;++i){
		min[i] = 1001; max[i] = -1;
		for(int j = 0;j<P;++j){
			if(comp[i][j]<min[i]) min[i] = comp[i][j];
			if(comp[i][j]>max[i]) max[i] = comp[i][j];
		}
	}
	
	int cont = 0;
	
	for(int i = 0;i<P;++i){
		int aux = 0;
		
		for(int j = 0;j<N && aux!=-1;++j){
			if(comp[j][i]==min[j]) ++aux;
			if(comp[j][i]==max[j]) aux = -1;
		}
		
		if(2*aux>=N){
			if(cont>0) printf(" ");
			printf("%d",i+1);
			++cont;
		}
	}
	
	if(cont==0) printf("0");
	printf("\n");
	
	return 0;
}
