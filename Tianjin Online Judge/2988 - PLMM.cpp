#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t,N,L,W,P,S;
    
    int cont;
    
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        scanf("%d %d %d",&N,&L,&W);
        
        cont=0;
        
        for(int j=0;j<N;j++){
            scanf("%d %d",&P,&S);
            
            if((W==S && P==0) || (W>S && P*1.0/(abs(W-S)) <= L*1.0/W)) cont++;
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
