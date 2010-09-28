#include<cstdio>

using namespace std;

int M;

int pot(int a, int b){
    if(b==0) return 1;
    
    int aux=pot(a,b/2);
    
    if(b%2==0) return (aux*aux)%M;
    else return (((a*aux)%M)*aux)%M;
}

int main(){    
    int T,H,A,B,sum;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&M,&H);
        
        sum=0;
        
        for(int j=0;j<H;j++){
            scanf("%d %d",&A,&B);
            
            sum=(sum+pot(A%M,B))%M;
        }
        
        printf("%d\n",sum);
    }
    
    return 0;
}
