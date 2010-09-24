#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,B,aux1,aux2,zeros,cont1,cont2;
    
    while(1){
        scanf("%d %d",&N,&B);
        if(N==0 && B==0) break;
        
        if(N==1){
            printf("0\n");
            continue;
        }
        
        aux1=B;
        zeros=(1<<20);
        
        for(int i=2;aux1!=1;i++){
            if(aux1%i==0){
                
                cont1=cont2=0;
                
                while(aux1%i==0){
                    aux1/=i;
                    cont1++;
                }
                
                aux2=N;
                
                while(aux2!=0){
                    cont2+=aux2/i;
                    aux2/=i;
                }
                
                zeros=min(zeros,cont2/cont1);
            }
        }
        
        printf("%d\n",zeros);
    }
    
    return 0;
}
