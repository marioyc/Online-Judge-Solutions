#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,NCS,NE,aux;
    
    double prom1,prom2;
    
    int IQ[200000];
    
    scanf("%d",&T);
    
    for(int caso=0;caso<T;caso++){
        scanf("%d %d",&NCS,&NE);
        
        prom1=0.0;
        prom2=0.0;
        
        for(int i=0;i<NCS;i++){
            scanf("%d",&IQ[i]);
            prom1+=IQ[i];
        }
        
        prom1/=NCS;
        
        for(int i=0;i<NE;i++){
            scanf("%d",&aux);
            prom2+=aux;
        }
        
        prom2/=NE;
        
        aux=0;
        
        for(int i=0;i<NCS;i++)
            if(IQ[i]<prom1 && IQ[i]>prom2) aux++;
        
        printf("%d\n",aux);
    }
    
    return 0;
}
