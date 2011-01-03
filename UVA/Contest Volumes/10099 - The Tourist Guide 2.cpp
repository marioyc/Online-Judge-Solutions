#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,R,C1,C2,P,S,D,T,cont;
    cont=1;
    
    int M[100][100];
    
    while(1){
        scanf("%d %d",&N,&R);
        if(N==0 && R==0) break;
        
        for(int i=0;i<N;i++) fill(M[i],M[i]+N,-1);
        
        for(int i=0;i<R;i++){
            scanf("%d %d %d",&C1,&C2,&P);
            
            M[C1-1][C2-1]=M[C2-1][C1-1]=P;
        }
        
        for(int i=0;i<N;i++) M[i][i]=0;
        
        scanf("%d %d %d",&S,&D,&T);
        
        if(S==D){
            printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cont,0);
            cont++;
            continue;
        }
        
        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    M[i][j]=max(M[i][j],min(M[i][k],M[k][j]));
        
        S--; D--;
        
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cont,(T+M[S][D]-2)/(M[S][D]-1));
        cont++;
    }
    
    return 0;
}
