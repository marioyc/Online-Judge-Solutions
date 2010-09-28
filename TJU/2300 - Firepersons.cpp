#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100
#define MOD 10000

int size;

struct M{
    int X[MAX_SIZE][MAX_SIZE];
		
	M(){
	}
};

void mult(M &m, M &m1, M &m2){
	memset(m.X,0,sizeof(m.X));
		
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			for(int k=0;k<size;k++)
				m.X[i][k]=(m.X[i][k]+m1.X[i][j]*m2.X[j][k])%MOD;
}

M M0,aux1,aux2;

M exp(int n){
	if(n==1) return M0;
	if(n==0){
        for(int i=0;i<size;i++) fill(aux1.X[i],aux1.X[i]+size,0);
        for(int i=0;i<size;i++) aux1.X[i][i]=1;
        return aux1;
    }
    
	aux1=exp(n/2);
	
    for(int i=0;i<size;i++) fill(aux2.X[i],aux2.X[i]+size,0);
    for(int i=0;i<size;i++) aux2.X[i][i]=1;
    
	mult(aux2,aux1,aux1);
	
	if(n%2==1){
        mult(aux1,aux2,M0);
        return aux1;
    }
    
	return aux2;
}

int main(){
    int k,a[100],b[100],m,x;
    
    while(1){
        scanf("%d",&k);
        if(k==0) break;
        
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        for(int i=0;i<k;i++) scanf("%d",&b[i]);
        
        scanf("%d",&m);
        
        if(m<k) printf("%d\n",a[m]);
        else{
            for(int i=0;i<k;i++) M0.X[0][i]=b[i];
            for(int i=1;i<k;i++){
                fill(M0.X[i],M0.X[i]+k,0);
                M0.X[i][i-1]=1;
            }
            
            size=k;
            M0=exp(m-k+1);
            
            x=0;
            for(int i=0;i<k;i++) x=(x+M0.X[0][i]*a[k-i-1])%MOD;
            
            printf("%d\n",x);
        }
    }
    
    return 0;
}
