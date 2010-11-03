#include <cstdio>
#include <cstring>

using namespace std;

int win[5][5][5][5][5][5];

int solve(int x1, int x2, int x3, int x4, int x5, int x6){
	if(win[x1][x2][x3][x4][x5][x6] != -1) return win[x1][x2][x3][x4][x5][x6];
	
	int p=84-x1-2*x2-3*x3-4*x4-5*x5-6*x6,aux=0;
	if(p>31) return 1;
	
	if(x1>0 && solve(x1-1,x2,x3,x4,x5,x6)==0) aux=1;
	if(x2>0 && solve(x1,x2-1,x3,x4,x5,x6)==0) aux=1;
	if(x3>0 && solve(x1,x2,x3-1,x4,x5,x6)==0) aux=1;
	if(x4>0 && solve(x1,x2,x3,x4-1,x5,x6)==0) aux=1;
	if(x5>0 && solve(x1,x2,x3,x4,x5-1,x6)==0) aux=1;
	if(x6>0 && solve(x1,x2,x3,x4,x5,x6-1)==0) aux=1;
	
	win[x1][x2][x3][x4][x5][x6]=aux;
	return aux;
}

int main(){
	memset(win,-1,sizeof(win));
	
	char moves[25];
	
	int L,x[6],ans;
	
	while(scanf("%s",moves)==1){
		L=strlen(moves);
		
		for(int i=0;i<6;i++) x[i]=4;
		
		for(int i=L-1;i>=0;i--) x[moves[i]-'1']--;
		
		ans=solve(x[0],x[1],x[2],x[3],x[4],x[5]);
		
		printf("%s ",moves);
		
		if(L&1){
			if(ans==1) printf("B\n");
			else printf("A\n");
		}else{
			if(ans==1) printf("A\n");
			else printf("B\n");
		}
	}
	
	return 0;
}
