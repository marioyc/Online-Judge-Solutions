#include <cstdio>
#include <algorithm>
#include <cstdio>

#include <iostream>

using namespace std;

#define MAX_SIZE 1000

int size,MOD;

struct M{
    long long X[MAX_SIZE];
		
	M(){
	}
};

void mult(M &m, M &m1, M &m2){
	memset(m.X,0,sizeof(m.X));
	
	for(int i=0;i<size;i++)
	   for(int j=0;j<size;j++)
	       m.X[i]=(m.X[i]+m1.X[j]*m2.X[(i+size-j)%size])%MOD;
}

M M0,aux1,aux2;

M exp(int n){
	if(n==1) return M0;
	if(n==0){
        fill(aux1.X,aux1.X+size,0);
        aux1.X[0]=1;
        return aux1;
    }
    
	aux1=exp(n/2);
	
    fill(aux2.X,aux2.X+size,0);
    aux2.X[0]=1;
    
	mult(aux2,aux1,aux1);
	
	if(n%2==1){
        mult(aux1,aux2,M0);
        return aux1;
    }
    
	return aux2;
}

int main(){
    int T,S,L,R,X,a[1000];
    M aux;
    long long ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d %d %d %d",&size,&S,&L,&R,&X);
        
        for(int i=0;i<size;i++) scanf("%d",&a[i]);
        
        fill(M0.X,M0.X+size,0);
        M0.X[0]=1;
        M0.X[size-1]=L;
        M0.X[1]=R;
        
        MOD=1;
        for(int i=0;i<X;i++) MOD*=10;
        M aux=exp(S);        
        
        for(int i=0;i<size;i++){
            ans=0;
            for(int j=0;j<size;j++) ans=(ans+aux.X[(j+size-i)%size]*a[j])%MOD;
            
            printf("%d",(int)ans);
            if(i==size-1) printf("\n");
            else printf(" ");
        }
    }
    
    return 0;
}
