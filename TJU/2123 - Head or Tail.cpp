#include<cstdio>

using namespace std;

int main(){
    int N,aux,cont1,cont2;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        cont1=cont2=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&aux);
            
            if(aux==0) cont1++;
            else cont2++;
        }
        
        printf("Mary won %d times and John won %d times\n",cont1,cont2);
    }
    
    return 0;
}
