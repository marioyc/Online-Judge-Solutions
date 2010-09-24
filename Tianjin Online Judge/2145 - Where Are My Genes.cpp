#include<cstdio>

using namespace std;

int main(){
    int N,R,Q;
    int rev_1[1000];
    int rev_2[1000];
    int x,cont=1;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        scanf("%d",&R);
        
        for(int i=0;i<R;i++) scanf("%d %d",&rev_1[i],&rev_2[i]);
        
        scanf("%d",&Q);
        
        printf("Genome %d\n",cont);
        cont++;
        
        for(int i=0;i<Q;i++){
            scanf("%d",&x);
            
            for(int j=0;j<R;j++)
                if(x>=rev_1[j] && x<=rev_2[j]) x=rev_1[j]+rev_2[j]-x;
            
            printf("%d\n",x);
        }
    }
    
    return 0;
}
